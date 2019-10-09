#include "DHT.h"
#define DHTPIN 2 // Select pin 2
#define DHTTYPE DHT11 // DHT 11
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

bool isPrint = false;

byte pac1[8] = {
    B00000,
    B01110,
    B11011,
    B11111,
    B11111,
    B01110,
    B00000,
    B00000
};

byte pac2[8] = {
    B00000,
    B01110,
    B10100,
    B11000,
    B11100,
    B01110,
    B00000,
    B00000
};

byte pac3[8] = {
    B00000,
    B00000,
    B00000,
    B01110,
    B11011,
    B11111,
    B11111,
    B01110

};

byte pac4[8] = {
    B00000,
    B00000,
    B00000,
    B01110,
    B10100,
    B11000,
    B11100,
    B01110
};

byte pac2b[8] = {
    B00000,
    B11110,
    B01011,
    B00111,
    B01111,
    B11110,
    B00000,
    B00000 
};

byte ghost[8] = {  
    B01110,
    B11111,
    B10101,
    B11111,
    B11111,
    B10101,
    B00000,
    B00000
};

byte punkt[8] = {
    B00000,
    B00000,
    B00000,
    B01100,
    B01100,
    B00000,
    B00000,
    B00000
};

byte tree1[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00100,
    B00100
};


byte tree2[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00100,
    B01110,
    B00100,
    B00100
};

byte tree3[8] = {
    B00000,
    B00100,
    B01110,
    B11111,
    B11111,
    B00100,
    B00100,
    B00100
};

byte flower1[8] = {
    B00000,
    B01110,
    B11011,
    B11111,
    B01110,
    B00100,
    B00100,
    B00000

};

byte flower2[8] = {
    B00000,
    B01110,
    B11111,
    B11111,
    B01110,
    B00100,
    B00100,
    B00000

};

byte carb[8] = {
    B00000,
    B00000,
    B01110,
    B01110,
    B01010,
    B11111,
    B11111,
    B10001

};


byte carb2[8] = {
    B00000,
    B00000,
    B01110,
    B01110,
    B01010,
    B11111,
    B11111,
    B01010

};

byte car1[8] = {
    B00000,
    B00000,
    B01110,
    B01110,
    B01010,
    B11111,
    B11111,
    B01010

};

byte car2[8] = {
    B00000,
    B00000,
    B01110,
    B01110,
    B01010,
    B11111,
    B11111,
    B10100
};

byte car3[8] = {
    B00000,
    B00000,
    B01110,
    B01110,
    B01010,
    B11111,
    B11111,
    B00101
};

byte car4[8] = {
    B00000,
    B00000,
    B01110,
    B01110,
    B01010,
    B11111,
    B11111,
    B10001
};

byte car5b[8] = {
    B00000,
    B00000,
    B00000,
    B11111,
    B10111,
    B10111,
    B11111,
    B10001
};


byte car5[8] = {
    B00000,
    B00000,
    B00000,
    B11111,
    B11101,
    B11101,
    B11111,
    B01010
};

byte car6[8] = {
    B00000,
    B00000,
    B00000,
    B11111,
    B11101,
    B11101,
    B11111,
    B10001
};

byte floor1[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
    B01110
};

byte floor2[8] = {
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B01110
};

byte mush1[8] = {
    B00000,
    B00100,
    B01110,
    B10101,
    B11111,
    B11111,
    B01010,
    B01010
};

byte mush2[8] = {
    B00000,
    B00100,
    B01110,
    B10101,
    B11011,
    B11111,
    B01010,
    B10001
};

byte floor3[8] = {
    B00000,
    B00000,
    B00000,
    B00100,
    B01110,
    B01110,
    B00100,
    B00000
};


byte top1[8] = {
    B01110,
    B11111,
    B01110,
    B00100,
    B00100,
    B00100,
    B00000,
    B00000
};

byte gift1[8] = {

    B00000,
    B00000,
    B00000,
    B00100,
    B01110,
    B00100,
    B00000,
    B00000
};

byte bottle1[8] = {
    B00000,
    B00100,
    B01110,
    B01010,
    B01010,
    B01010,
    B01010,
    B01110
};

byte bottle2[8] = {
    B00000,
    B00100,
    B01110,
    B01010,
    B01010,
    B01010,
    B01110,
    B01110
};

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor
float h,t,f;

void setup() {
    Serial.begin(9600); // baud rate 9600</strong>
    Serial.println("DHTxx test!");
    dht.begin(); // Start DHT</strong>
    lcd.begin(16,2);
    lcd.backlight();


    lcd.createChar(1, pac1);  
    lcd.createChar(2, pac2);   
    lcd.createChar(3, ghost);  
    lcd.createChar(4, punkt);  
    lcd.createChar(5, pac2b);
    lcd.createChar(6, tree1);
    lcd.createChar(7, tree2);
    lcd.createChar(8, tree3);


    delay(2000);
}

void print_temp_humid(){ // Display temperature and humidity
    lcd.setCursor(0, 0);
    lcd.print(String("  ") + "H:" + int(h) + "%");
    lcd.print(String(" ") + "T:"+ int(t) + (char)223 + "C");
}

void print_pac(){  // Display Pacman animation

    lcd.createChar(1, pac1);  
    lcd.createChar(2, pac2);   
    lcd.createChar(3, ghost);  
    lcd.createChar(4, punkt);  
    lcd.createChar(5, pac2b);

    for(int i = 0; i < 16; i++){
        delay(100);
        lcd.setCursor(i*2+1,1);
        lcd.write(4);
    }

    for(int i = 0; i < 16; i++){
        if(i >=2){
            lcd.setCursor(i-2,1);
            lcd.write(3);
        }

        lcd.setCursor(i,1);
        if(i%2==0)
            lcd.write(2);
        else
            lcd.write(1);

        delay(410);
        lcd.setCursor(i,1);
        lcd.write(" ");

        if(i >=2){
            lcd.setCursor(i-2,1);
            lcd.write(" ");
        }
    }

    for(int i = 15; i >=0; i--){
        delay(100);
        lcd.setCursor(i*2,1);
        lcd.write(4);

    }

    delay(1000);
    for(int i = 15; i >=0; i--){

        lcd.setCursor(i,1);
        if(i%2==0)
            lcd.write(1);
        else
            lcd.write(5);

        delay(410);
        lcd.setCursor(i,1);
        lcd.write(" ");

    }

}

void print_tree(){

    lcd.createChar(6, tree1);
    lcd.createChar(7, tree2);
    lcd.createChar(8, tree3);
    for(int i = 0; i < 16; i++){
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(6);
        }
        delay(100);
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(7);
        }

        delay(100);
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(8);
        }
    }

    delay(1000);  

    for(int i = 15; i >=0; i--){
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(8);
        }
        delay(60);
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(7);
        }

        delay(60);
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(6);
        }

        delay(60);
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(" ");
        }

    }
}

void print_flower(){
    lcd.createChar(4, flower1);
    lcd.createChar(5, flower2);
    delay(1000);  
    for(int i = 0; i < 16; i++){
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(4);
        }
        delay(100);
    }

    delay(500); 

    for(int i = 15; i >=0; i--){
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(5);
        }
        delay(200);
    }

    delay(500); 


    for(int i = 0; i < 16; i++){

        delay(100);
        if(i%2){
            lcd.setCursor(i,1);
            lcd.write(" ");
        }
    }


}

void print_car(){
    lcd.createChar(1, car1); 
    lcd.createChar(2, car2); 
    lcd.createChar(3, car3); 
    lcd.createChar(4, car4); 
    lcd.createChar(5, car5); 
    lcd.createChar(6, car6); 
    lcd.createChar(7, floor1); 
    lcd.createChar(8, floor2); 
    delay(100);

    for(int i = 0; i < 16; i++){
        delay(100);
        lcd.setCursor(i,1);
        if(i%2)
            lcd.write(7);
    }

    delay(100);
    for(int i = 0; i < 16; i++){

        lcd.setCursor(i,1);
        lcd.write(1);
        delay(100);
        lcd.setCursor(i,1);
        lcd.write(2);
        delay(100);
        lcd.setCursor(i,1);
        lcd.write(3);
        delay(100);
        lcd.setCursor(i,1);
        lcd.write(4);
        delay(100);
        lcd.setCursor(i,1);
        lcd.write(" ");
    }


    delay(200);
    for(int i = 15; i >= 0; i--){
        delay(100);
        lcd.setCursor(i,1);
        lcd.write(8);
    }

    delay(100);
    for(int i = 15; i >= 0; i--){

        lcd.setCursor(i,1);
        lcd.write(1);
        delay(80);
        lcd.setCursor(i,1);
        lcd.write(2);
        delay(80);
        lcd.setCursor(i,1);
        lcd.write(3);
        delay(80);
        lcd.setCursor(i,1);
        lcd.write(4);
        delay(80);
        lcd.setCursor(i,1);
        lcd.write(" ");
    }



    lcd.createChar(1, top1); 
    lcd.createChar(5, car5); 
    for(int i = 0; i < 16; i++){
        delay(100);
        lcd.setCursor(i,1);
        if(i%2)
            lcd.write(1);
    }

    delay(100);
    for(int i = 0; i < 16; i++){
        lcd.setCursor(i,1);
        if(i%2)
            lcd.write(5);
        else
            lcd.write(6);
        delay(400);

        lcd.setCursor(i,1);
        lcd.write(" ");
    }

    lcd.createChar(5, car5b); 
    delay(500);
    for(int i = 15; i >=0; i--){

        lcd.setCursor(i,1);
        lcd.write(5);
        delay(300);
        lcd.setCursor(i,1);
        lcd.write(" ");
    }
}

void print_man(){

    lcd.createChar(1, mush1);
    lcd.createChar(2, mush2);
    lcd.createChar(3, gift1);

    delay(100);

    for(int i = 0; i < 16; i++){
        delay(100);
        lcd.setCursor(i,1);
        if(i%2)
            lcd.write(3);
    }

    delay(300);  


    for(int i = 0; i < 16; i++){

        lcd.setCursor(i,1);
        if(i%2)
            lcd.write(1);
        else
            lcd.write(2);

        delay(300);

        lcd.setCursor(i,1);
        lcd.write(" ");

    }


}

void loop() {

    h = dht.readHumidity();        // Humidity
    t = dht.readTemperature();     // Celsius
    f = dht.readTemperature(true); // Fahrenheit

    if (isnan(h) || isnan(t) || isnan(f)) {
        //Serial.println("Can't read from DHT!");
        //return; debug only
    }
    
    /* Print message to console. Debug only
       Serial.print("Humidity: ");  
       Serial.print(h);
       Serial.print(" %\t");
       Serial.print("Temperature: ");
       Serial.print(t);
       Serial.print(" *C ");
       Serial.print(f);
       Serial.println(" *F\t");
    */  
    
    //Display temperature and humidity
    print_temp_humid();

    delay(100);
    print_pac();
    print_car();
    print_flower();
    print_man();
    print_tree();

    delay(3000);

}
