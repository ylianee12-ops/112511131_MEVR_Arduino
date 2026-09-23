# 課題報告：Advanced Task 2-1 Potentiometer Direction & Speed Control

- **學生姓名**：邱子澄
- **學生學號**：112511131
- **完成日期**：2026-09-23

---

### 1. 實驗目標(可參考課程投影片寫法)

- 認識 L293D 馬達驅動 IC 的腳位與使用方式。
- 使用 Arduino 的數位輸出控制 DC 馬達的旋轉方向。
- 使用可變電阻輸入與 PWM，控制 DC 馬達的旋轉方向與速度。

### 2. 設備與元件

- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- 麵包板 × 1
- DC 馬達 × 1
- L293D 馬達驅動 IC × 1
- 10 kΩ 可變電阻 × 1
- 杜邦線
- 馬達電源

### 3. 操作說明與成果

1. 將 L293D 放置在麵包板中央，Pin 16 接 Arduino 5V，Pin 4、5、12、13 接 GND，Pin 8 接 5V。
2. 將 L293D 的 Enable Pin 1 接至 Arduino D5，方向控制腳 Pin 2、Pin 7 分別接至 D8、D9；DC 馬達的兩端則接至 L293D Pin 3、Pin 6。
3. 將可變電阻兩側接至 5V 與 GND，中間腳接至 A0。Arduino 使用 analogRead() 取得 0～1023 的數值，依照數值順時針或逆時針旋轉，並將距離 512 的中間值轉換成 0～255 的 PWM 輸出，控制馬達速度。
4. 實驗結果：analogRead() 若取得 0～461 的數值則順時針旋轉，越靠近 0 轉的速度越快，若在 563～1023 之間則逆時針，越靠近 1023 越快，中間則是緩衝的停止區域。
5. 實際成果：DemoVideo/Task 2-1.mp4。