# 課題報告：Advanced Task 3-1 Timer Interrupt vs Blocking Delay

- **學生姓名**：邱子澄
- **學生學號**：112511131
- **完成日期**：2026-10-01

---

### 1. 實驗目標(可參考課程投影片寫法)

- 使用 TimerOne 函式去進行 Timer Interrupt
- 了解 ISR 與 Loop 的差別


### 2. 設備與元件

- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- 麵包板 × 1
- RED LED × 1
- BLUE LED × 1
- Button × 2
- 杜邦線

### 3. 操作說明與成果

1. 將電路照著 Wiring.txt 依序接好。
2. Arduino 設置每 50ms 進行一次 timer interrupt，並執行 void timerISR() 即時偵測 Button 的狀態變化。
3. 實驗結果：以下稱使用 ISR 的 LED 為 RED、使用 ISR 的 LED 為 BLUE，RED 基本上可以即時偵測 Button 的狀態變化造成 LED 的開關；BLUE 則需要在 delay 之外才能偵測 Button的狀態變化。
4. 實際成果：DemoVideo/Task 3-1.mp4。

