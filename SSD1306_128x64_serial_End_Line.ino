#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET 4 // not used / nicht genutzt bei diesem Display
Adafruit_SSD1306 display(OLED_RESET);

 char inChar;
 String string;


void setup()   { 

  pinMode(13, OUTPUT);
  
 // initialize with the I2C addr 0x3C / mit I2C-Adresse 0x3c initialisieren
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
                 
  Serial.begin(115200);
  string.reserve(200);

  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(0.5);
  display.setTextColor(INVERSE); 
}

void loop()
{ 
  
  if (Serial.available())  {
    
                display.clearDisplay();
                inChar = Serial.read();
                string+=inChar;               
                display.setCursor(0,0); 
                display.print(string);               
                display.display();   

           

          
              if( inChar == '\r'){
                    Serial.println("End");                
                    delay(4000);
                    string="";
                  
              }  
             
        
    }  

   
  display.display(); 
  
}
