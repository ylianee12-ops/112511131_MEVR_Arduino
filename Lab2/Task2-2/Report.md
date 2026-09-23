**`Lab2/Task2-2/report.md`（完整示範報告）**

```markdown
# 課題報告：Advanced Task 2-2 Servo Motor Control with an Ultrasonic Sensor

- **學生姓名**：邱子澄
- **學生學號**：112511131
- **完成日期**：2026-09-23

---

### 1. 實驗目標(可參考課程投影片寫法)
- 使用 Servo Library 控制 SG90 伺服馬達的角度。
- 了解如何使用 HC-SR04 超音波感測器的腳位並用來測量物體距離。
- 將測得的距離轉換為 SG90 的旋轉角度。

### 2. 設備與元件
- Arduino Uno 開發板 x 1
- USB Type-B 傳輸線 x 1
- 個人電腦（已安裝 Arduino IDE）x 1
- 麵包板 × 1
- SG90 伺服馬達 × 1
- HC-SR04 超音波感測器 × 1
- 杜邦線

### 3. 操作說明與成果
1. 將 SG90 的訊號線接至 Arduino D9，電源線與接地線分別接至 5V 與 GND；使用 myservo.attach(9) 指定控制腳位，並以 myservo.write(angle) 控制角度。
2. 將 HC-SR04 的 Trig 接至 D7、Echo 接至 D6，VCC 與 GND 分別接至 5V 與 GND。
3. Arduino 在 Trig 輸出 10 μs 的 HIGH 訊號，並使用 pulseIn() 測量 Echo 維持 HIGH 的時間。
4. Echo 維持 HIGH 的時間為超音波抵達物體後再反射回感測器的來回時間，因此距離計算式為 distance = duration × 0.0343 ÷ 2。
5. 將 5～30 cm 的距離限制並線性轉換為 0～180°。物體距離感測器越遠，SG90 的角度越大；距離小於 5 cm 時維持 0°，大於 30 cm 時維持 180°。
6. 實驗結果：移動手掌與 HC-SR04 之間的距離時，Serial Monitor 顯示的距離與角度會隨之改變，SG90 也能依照計算結果轉至相對應的位置。
7. 實際成果：DemoVideo/Task 2-2.mp4。