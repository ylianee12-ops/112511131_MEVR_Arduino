# 課題報告：Advanced Task 2-3 External Interrupt vs Polling

- **學生姓名**：邱子澄
- **學生學號**：112511131
- **完成日期**：2026-09-23

---

### 1. 實驗目標(可參考課程投影片寫法)

- 使用 Arduino Uno 的外部中斷控制 LED 狀態。
- 了解 attachInterrupt()、ISR 與外部中斷之間的關係。
- 使用 Polling 與 Edge Detection 控制第二組按鈕及 LED。
- 透過 delay(2000) 比較 External Interrupt 與 Polling 在系統 Blocking 時的差異。

### 2. 設備與元件

- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- 麵包板 × 1
- RED LED × 1
- BLUE LED × 1
- 220 Ω 限流電阻 × 2
- 按鈕 × 2
- 杜邦線

### 3. 操作說明與成果

1. Button A 接至支援外部中斷的 D2，LED A 接至 D5；Button B 接至 D4，LED B 接至 D10。兩個按鈕皆使用 INPUT_PULLUP，因此沒有按下時為 HIGH，按下時為 LOW。
2. attachInterrupt() 用來登記要監視的中斷腳位、觸發方式及要執行的 ISR；當外部中斷發生時，Arduino 會暫停目前的主程式，執行 buttonISR()，ISR 結束後才回去繼續執行。
3. Button B 使用 Polling。程式比較 lastButtonStateB 和 currentButtonStateB，只有上一次為 HIGH、這一次為 LOW 時，才判定偵測到一次按下並切換 LED B。
4. 實驗結果：Button A 使用 External Interrupt，即使程式正在 delay，短按仍能立即切換 LED A；Button B 在完成一次切換後，程式還必須讀取到放開時的 HIGH，之後再次讀取到按下時的 LOW，才能形成新的 HIGH to LOW Edge。若放開狀態也發生在 delay 期間，下一次長按仍可能因為前後讀值都是 LOW 而沒有切換。
5. 實際成果：DemoVideo/Task 2-3.mp4。
