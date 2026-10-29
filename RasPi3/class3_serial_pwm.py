
import serial
import time

PORT = "/dev/ttyUSB0"
BAUD_RATE = 115200

def send_pwm(ser, pwm):
    command = f"PWM:{pwm}\n"
    expected = f"ACK:PWM:{pwm}"

    ser.write(command.encode("ascii"))
    ser.flush()

    reply = ser.readline().decode(errors="replace").strip()

    print(f"Sent: PWM:{pwm}")
    print(f"Received: {reply}")

    if reply != expected:
        raise RuntimeError(f"Expected {expected}, got {reply!r}")

with serial.Serial(PORT, BAUD_RATE, timeout=2) as ser:
    time.sleep(2)
    ser.reset_input_buffer()

    try:
        for pwm in [0, 120, 180, 0]:
            send_pwm(ser, pwm)
            time.sleep(2)
    finally:
        # 測試結束時嘗試停止馬達
        send_pwm(ser, 0)

print("PWM serial test completed!")
