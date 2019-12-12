/* REF: https://swf.com.tw/?p=930
 * xiaolaba, 2019-DEC-12
 * Arduino 1.8.9
 * Nano
 */

#include <SPI.h>
#include <MFRC522.h>     // 引用程式庫

#define RST_PIN      9         // 讀卡機的重置腳位
#define SS_PIN       10        // 晶片選擇腳位

MFRC522 mfrc522(SS_PIN, RST_PIN);  // 建立MFRC522物件

int8_t seq =0;

void setup() {
  Serial.begin(115200);
  Serial.println("MIFARE 13.56MHz RFID reader is ready!");

  SPI.begin();
  mfrc522.PCD_Init();   // 初始化MFRC522讀卡機模組
}

void loop() {
    // 確認是否有新卡片
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      byte *id = mfrc522.uid.uidByte;   // 取得卡片的UID
      byte idSize = mfrc522.uid.size;   // 取得UID的長度
      byte sak = mfrc522.uid.sak;       // 取得SAK

      seq++;
      Serial.print(seq, DEC);
      
      Serial.print(", PICC type: ");      // 顯示卡片類型
      // 根據卡片回應的SAK值（mfrc522.uid.sak）判斷卡片類型
      MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      Serial.print("SAK: 0x");       // 顯示卡片的SAK
      if (sak < 0x10) { Serial.print("0");} // 如果 0-F, 補零對齊兩位HEX, 00-0F 
      {Serial.println(sak, HEX);}

      Serial.print("UID Size: ");       // 顯示卡片的UID長度值
      Serial.println(idSize);

      Serial.print("UID (HEX): ");    // 以16進位顯示UID值
      for (byte i = 0; i < idSize; i++) {
        if (id[i] < 0x10) { Serial.print("0");} // 如果 0-F, 補零對齊兩位HEX, 00-0F      
        Serial.print(id[i], HEX);       
        if (i < (idSize -1) ) {Serial.print(":");}  //分隔符號 
      } 
      Serial.println();

      Serial.print("UID (DEC): ");    // 以10進位顯示UID值
      for (byte i = 0; i < idSize; i++) {
        Serial.print(id[i], DEC);       
        if (i < (idSize -1) ) {Serial.print(" ");}  //分隔符號
      }
      Serial.println();
      Serial.println();
      
      mfrc522.PICC_HaltA();  // 讓卡片進入停止模式
    } 
}
