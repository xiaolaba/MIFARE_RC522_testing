# MIFARE_RC522_testing
MIFARE RC522 testing  

REF: https://swf.com.tw/?p=930

MIFARE NXP datasheet, ![AN10833.pdf](AN10833.pdf)  
![MFRC522_Standard_performance MIFARE_and_NTAG_frontend_Rev3.9_27_ April_2016.pdf](MFRC522_Standard_performance MIFARE_and_NTAG_frontend_Rev3.9_27_ April_2016.pdf)  

Arduino IDE 1.8.9  
import & install library for RC522

![xiaolaba_MIFARE_RC522_testing_add_library.jpg](xiaolaba_MIFARE_RC522_testing_add_library.jpg)  

![xiaolaba_MIFARE_RC522_testing_install_library.jpg](xiaolaba_MIFARE_RC522_testing_install_library.jpg)

  
hardware setup  
  
Arduino Nano pin# <-> RC522 pin#

3.3V - VCC  
GND - GND  
D9 - RST  
D10 - NSS  
D11 - MO  
D12 - MI  
D13 - SCK  

![xiaolaba_MIFARE_RC522_testing.jpg](xiaolaba_MIFARE_RC522_testing.jpg)  
  
Output  
![xiaolaba_MIFARE_RC522_testing_output.jpg](xiaolaba_MIFARE_RC522_testing_output.jpg)

source code, ![RC522test.ino](RC522test.ino)  
pre-build hex also included.

