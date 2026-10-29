
from pathlib import Path
import argparse
import time

import serial
from picamera2 import Picamera2
from ultralytics import YOLO

from class3_decision import decide_pwm

PORT = "/dev/ttyUSB0"
BAUD_RATE = 115200

MODEL_PATH = (
    Path(__file__).resolve().parents[1]
    / "class2" / "models" / "yolo11n.pt"
)

def send_pwm(ser, pwm):
    command = f"PWM:{pwm}\n"
    print("Serial Command:", command.strip())

    ser.write(command.encode("ascii"))
    ser.flush()

    reply = ser.readline().decode(
        errors="replace"
    ).strip()

    print("Arduino Reply:", reply)

    if reply != f"ACK:PWM:{pwm}":
        raise RuntimeError("Invalid Arduino ACK")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--live", action="store_true")
    parser.add_argument("--frames", type=int, default=20)
    args = parser.parse_args()

    model = YOLO(str(MODEL_PATH))
    picam2 = None
    ser = None
    camera_started = False
    previous_pwm = None

    try:
        if args.live:
            ser = serial.Serial(
                PORT, BAUD_RATE, timeout=2
            )
            time.sleep(2)
            ser.reset_input_buffer()
            send_pwm(ser, 0)
            previous_pwm = 0

        picam2 = Picamera2()
        config = picam2.create_preview_configuration(
            main={
                "size": (640, 480),
                "format": "RGB888"
            }
        )
        picam2.configure(config)
        picam2.start()
        camera_started = True
        time.sleep(2)

        print("YOLO Motor Demo Started")
        print("Mode:", "LIVE" if args.live else "DRY RUN")

        for i in range(args.frames):
            frame = picam2.capture_array()

            results = model.predict(
                source=frame,
                device="cpu",
                verbose=False
            )

            result = results[0]
            detected = []

            for box in result.boxes:
                class_id = int(box.cls[0].item())
                detected.append(result.names[class_id])

            pwm = decide_pwm(detected)

            print(f"\nFrame {i + 1}")
            print("Detected Classes:", detected)
            print("PWM Target:", pwm)

            if pwm != previous_pwm:
                if args.live:
                    send_pwm(ser, pwm)
                else:
                    print(f"DRY RUN: PWM:{pwm}")

                previous_pwm = pwm

    except KeyboardInterrupt:
        print("\nStopped by user.")

    finally:
        if ser is not None:
            try:
                send_pwm(ser, 0)
            except Exception as e:
                print("WARNING: Stop command failed:", e)
            ser.close()

        if picam2 is not None and camera_started:
            picam2.stop()

        print("Demo finished.")


if __name__ == "__main__":
    main()
