
import serial
import time

PORT = "/dev/ttyUSB0"
BAUD_RATE = 115200

def send_command(ser, command, expected):
    # 傳送指令
    ser.write((command + "\n").encode("ascii"))
    ser.flush()
    print("Sent:", command)

    # 讀取 Arduino 回覆
    reply = ser.readline().decode(errors="replace").strip()
    print("Received:", reply)

    if reply != expected:
        raise RuntimeError("Unexpected response: " + repr(reply))

with serial.Serial(PORT, BAUD_RATE, timeout=2) as ser:
    time.sleep(2)
    ser.reset_input_buffer()

    # 開啟 LED
    send_command(ser, "LED:ON", "ACK:ON")

    # 保持亮燈 3 秒
    time.sleep(3)

    # 關閉 LED
    send_command(ser, "LED:OFF", "ACK:OFF")

print("LED control test completed!")
