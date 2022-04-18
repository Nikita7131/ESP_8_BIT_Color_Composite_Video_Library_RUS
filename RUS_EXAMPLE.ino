#include <ESP_8_BIT_GFX.h>
ESP_8_BIT_GFX videoOut(true, 8);

void setup() { 
   videoOut.begin();
   videoOut.setTextWrap(false);  

}

void loop() {
  
    videoOut.waitForFrame();
    videoOut.fillScreen(0);  
    videoOut.setTextColor(0xFF);
    
    videoOut.setTextSize(2);            
    videoOut.setCursor(20, 20);
    videoOut.print(utf8rus("привет кусок мяса")); 
    videoOut.setCursor(50, 40);
    videoOut.setTextSize(1);    
    videoOut.print(utf8rus("я умею писать по русски")); 
    videoOut.setTextSize(2);    
    videoOut.setCursor(30, 60);
    videoOut.print("ESP_8_BIT_GFX.h"); 
    
    videoOut.setCursor(25, 90);
    videoOut.setTextSize(1);    
    videoOut.print(utf8rus("абвгдеёжзийклмнопрстуфхцчшщъыьэюя")); 
    videoOut.setCursor(40, 110);
    videoOut.setTextSize(1);    
    videoOut.print("abcdefghijklmnopqrstuvwxyz"); 
    videoOut.setCursor(40, 130);
    videoOut.setTextSize(1);    
    videoOut.print("ESP32 & AV out (239*255)"); 
        
}
String utf8rus(String source) {
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };
  k = source.length(); i = 0;
  while (i < k) {
    n = source[i]; i++;
    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x30;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB8; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x70;
          break;
        }
      }
    }
    if(n >= 192){   
      n --; 
    }
    m[0] = n;
    target = target + String(m);
  }
return target;
}
