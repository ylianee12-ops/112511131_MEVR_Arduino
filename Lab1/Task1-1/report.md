# 課題報告：Task 1-1 Using the variable resistor to adjust LED lightness

- **學生姓名**：邱子澄
- **學生學號**：112511131
- **完成日期**：2026-09-13

---

### 1. 實驗目標(可參考課程投影片寫法)

- 使用 `analogRead()` 讀取可變電阻的分壓數值。
- 根據讀取到的數值，透過 PWM 調整 LED 亮度
(int brightness = map(analogValue, 0, 1023, 0, 255);)。
- 每秒在 Serial Monitor 顯示一次可變電阻讀到的數值。

### 2. 設備與元件

- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- 麵包板 × 1
- 紅色 LED × 1
- 10 kΩ 可變電阻 × 1
- 220 Ω 限流電阻 × 1
- 杜邦線

### 3. 操作說明與成果

1. 將可變電阻兩側接至 `5V` 和 `GND`，中間腳接至 `A0`；LED 則由 `D9` 經過 220 Ω 限流電阻後接至 `GND`。
2. 上傳 `Task1-1.ino`，並以 9600 baud 開啟 Serial Monitor。
3. 旋轉可變電阻時，LED 亮度會變亮/變暗，並且顯示的數值也會同時增加/減少。
4. 因為 Arduino Uno 10-bit ADC，會把 0～5 V 分成 1024 個數值，因此`analogRead()` 讀到的數值範圍是 0～1023。
5. 實驗結果：觀察到數值低於約 250 ，LED 變暗時比較容易被人眼辨識，如果太亮其實些微的變化看不太出來；此外，這次實驗過程中主要卡在沒有共同接地，後來發現是因為跟以前常用的麵包板不同，這次的麵包板同一側分成兩個不同的接地區域所導致。
6. 實際成果：`DemoVideo/Task1-1.mp4`。