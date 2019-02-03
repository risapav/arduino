    /*
    * Arduino LCD Tutorial
    *
    * Crated by Dejan Nedelkovski,
    * www.HowToMechatronics.com
    *
    */

    #include <OneWire.h>
    #include <DallasTemperature.h>
    #include <LiquidCrystal.h> // includes the LiquidCrystal Library 
    //cerpadlo
    #define CERPADLO_CHOD 1
    #define CERPADLO_STOP 0
    #define TEPLOTA_MAX 45.0

    //relre je na pine 3
    int relayPin = 3; 
    /* DS18S20 Temperature chip i/o */
    #define MAX_DS1820_SENSORS 5
    int num_temp = 0; //pocet teplomerov pripojenych
      //teplota[0] = T1 -teplota kolektora
      //teplota[1] = T2 -teplota v bojleri
      //teplota[2] = T3 -teplota okolia
    float teplota[MAX_DS1820_SENSORS];
    
    // vytvoření instance oneWireDS z knihovny OneWire
    OneWire  oneWireDS(13);  // on pin 13
    // vytvoření instance senzoryDS z knihovny DallasTemperature
    DallasTemperature senzoryDS(&oneWireDS);
    
    byte addr[MAX_DS1820_SENSORS][8];
    char buf[20];


    /* LCD display 1602A */
    #define LCD_WIDTH 16
    #define LCD_HEIGHT 2
    LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

    
    void setup() { 
        lcd.begin(LCD_WIDTH, LCD_HEIGHT); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
        
        //napis uvodny text
        lcd.setCursor(0,0);
        lcd.print("(@) Peter Risa");
        lcd.setCursor(0,1);
        lcd.print("Slnecny kolektor");
        delay(3000); // 3 seconds delay 

        // zapnutí komunikace knihovny s teplotním cidlom
        senzoryDS.begin();
        
        //zisti pocet teplomerov
        lcd.clear(); // Clears the LCD screen
        lcd.setCursor(0,0);
        lcd.print("DS1820 Test");

        byte i;
        for(i=0;i<MAX_DS1820_SENSORS;i++)
        {  
          if (!oneWireDS.search(addr[i]))
          { 
            lcd.setCursor(0,1);
            lcd.print("No more addresses.");
            oneWireDS.reset_search();
            delay(250);
            break;        
            
          }
          num_temp = i+1;
          sprintf(buf, "Pocet teplomerov: %d",num_temp);
          lcd.setCursor(0,1);
          lcd.print(buf);
          delay(2000);
        }
        lcd.setCursor(0,0);
        lcd.print("Aktualny stav");
        //iniciacia rele modulu
        pinMode(relayPin, OUTPUT);  //Set pin for output
        digitalWrite(relayPin, HIGH);  // HIGH is off, LOW is on
    }

   
    void loop() { 
/*      
      lcd.setCursor(1,0); 
      lcd.blink(); //Displays the blinking LCD cursor
      delay(2000);
      lcd.noBlink(); // Turns off the blinking LCD cursor
      lcd.setCursor(1,0);
      lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
      delay(2000); 
      lcd.noCursor(); // Hides the LCD cursor 
      lcd.clear(); // Clears the LCD screen
*/
   // nacita vsetky teplomery
      byte sensor;
      senzoryDS.requestTemperatures();
    // ulozi teploty do pola teplota
      for (sensor=0;sensor<num_temp;sensor++)
        {
          teplota[sensor]=senzoryDS.getTempCByIndex(sensor);
        }
        

    // spusti cerpadlo po vyhodnoteni teplot
      int cerpadlo=CERPADLO_STOP;
    //  cerpadlo ma bezat ak
    //  teploty su aspon 2
      if(num_temp<2)
        return;
    // ak teplota T0 je o 5.0 stupnov vacsia ako T1 spusti cerpadlo
      if(teplota[0]>(teplota[1]+4.0))
        cerpadlo=CERPADLO_CHOD;
    // ak teplota T1 je viac ako TEPLOTA_MAX stupnov zastav cerpadlo, aby sme neprehriali bojler
      if(teplota[1]>40.0)
        cerpadlo=CERPADLO_STOP;

//teraz vypni alebo zapni cerpadlo    
      if(cerpadlo==CERPADLO_CHOD)
        {
        digitalWrite(relayPin, LOW);
        }
      else
        {
        digitalWrite(relayPin, HIGH);
        }
      //zobraz teplotu na displej uloz ich do pola teplot
      for (sensor=0;sensor<num_temp;sensor++)
        {
          lcd.setCursor(0,1);
          sprintf(buf, "C: %d, T%d: ",cerpadlo, sensor+1);
          lcd.print(buf);
          lcd.print(teplota[sensor]);
          delay(1000);
        }

    }
