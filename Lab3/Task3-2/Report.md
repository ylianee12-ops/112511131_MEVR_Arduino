# 課題報告：Advanced Task 3-2 LED Control with Serial Communication

- **學生姓名**：邱子澄
- **學生學號**：112511131
- **完成日期**：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)

- 使用 Serial Communication 建立電腦端與 Arduino 之間的通訊。
- 用 Visual Studio 製作 C# GUI，透過按鈕傳送控制指令至 Arduino。
- 讓 Arduino 根據電腦端傳送的資料控制 LED 開啟與關閉。
- 了解 Serial Port、Baud Rate 與 Arduino Serial 之間的關係。

### 2. 設備與元件

- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE 與 Visual Studio）x 1
- 麵包板 × 1
- LED × 1
- 220 Ω 限流電阻 × 1
- 杜邦線

### 3. 操作說明與成果

1. 將 LED 接至 Arduino D6，並串聯 220 Ω 限流電阻後接至 GND。
2. Arduino 使用 `Serial.begin(9600)` 建立序列通訊，並在 `loop()` 中利用 `Serial.available()` 判斷是否收到資料，再以 `Serial.read()` 讀取一個字元。
3. 使用 Visual Studio 建立 C# 程式，設定與 Arduino 相同的 9600 baud，並使用 Serial Port 與 Arduino 連線。
4. GUI 中設置 `LED ON` 與 `LED OFF` 兩個按鈕。按下 `LED ON` 時，C# 程式透過 Serial Port 傳送字元 `"1"`；按下 `LED OFF` 時則傳送 `"0"`。
5. Arduino 收到字元 `'1'` 時，使用 `digitalWrite(ledPin, HIGH)` 開啟 LED；收到 `'0'` 時則使用 `digitalWrite(ledPin, LOW)` 關閉 LED。
6. 實驗結果：C# GUI 可透過 USB Serial Communication 即時控制 Arduino 上 LED 的開啟與關閉，成功建立電腦端應用程式與 Arduino 之間的通訊。
7. 實際成果：DemoVideo/Task3-2.mp4。