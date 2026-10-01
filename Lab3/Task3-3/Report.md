# 課題報告：Advanced Task 3-3 HC-05 Wireless LED Control

- **學生姓名**：邱子澄
- **學生學號**：112511131
- **完成日期**：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)

- 使用 HC-05 Bluetooth Module 建立電腦與 Arduino 之間的無線通訊。
- 使用 SoftwareSerial 建立 Arduino 與 HC-05 之間的 Serial Communication。
- 將 Advanced Task 3-2 的 USB Serial LED 控制方式改為 Bluetooth 無線控制。


### 2. 設備與元件

- Arduino Uno 開發板 x 1
- USB 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE、Visual Studio 與 Bluetooth）x 1
- 麵包板 × 1
- HC-05 Bluetooth Module × 1
- LED × 1
- 220 Ω 限流電阻 × 1
- 220 Ω 電阻 × 3
- 杜邦線


### 3. 操作說明與成果

1. 將 LED 接至 Arduino D6，並串聯 220 Ω 限流電阻後接至 GND。HC-05 的 VCC 與 GND 分別接至 Arduino 5V 與 GND。
2. 使用 `SoftwareSerial bluetooth(10, 11)` 建立第二組 Serial Communication，其中 Arduino D10 為 RX、D11 為 TX，因此 HC-05 TXD 接至 Arduino D10，Arduino D11 則接至 HC-05 RXD。
3. 由於 Arduino TX 的 HIGH 為約 5V，而 HC-05 RXD 為 3.3V，因此在 Arduino D11 與 HC-05 RXD 之間加入分壓器：使用一個 220 Ω 與兩個串聯的 220 Ω 電阻，使輸出電壓由約 5V 降至約 3.3V。
4. Arduino 使用 `bluetooth.begin(9600)` 與 HC-05 通訊。程式利用 `bluetooth.available()` 判斷是否有 Bluetooth 資料，再以 `bluetooth.read()` 讀取指令。
5. C# GUI 與 Advanced Task 3-2 相同，按下 `LED ON` 時傳送 `"1"`，按下 `LED OFF` 時傳送 `"0"`。Arduino 收到 `'1'` 時開啟 LED，收到 `'0'` 時關閉 LED。
6. 實驗結果：電腦可透過 Bluetooth 與 HC-05 無線傳送控制指令至 Arduino，並成功使用 C# GUI 控制 LED 開啟與關閉，不再需要使用 USB Serial 作為控制資料的傳輸通道。
7. 實際成果：DemoVideo/Task3-3.mp4。