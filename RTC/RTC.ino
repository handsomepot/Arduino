#include <DS1302.h>

// initialize DS1302
// DS1302 rtc([RST], [DAT], [CLOCK]); 
DS1302 rtc(10, 9, 8);

void setup() {
    rtc.halt(false); // normal mode

    //rtc.writeProtect(false);

    Serial.begin(9600); // baud rate 9600

    //rtc.setDOW(FRIDAY);         // Day
    //rtc.setTime(21, 35, 0);     // HH:MM:SS (24hr format)
    //rtc.setDate(5, 8, 2016);    // DD:MM::YY
}

void loop() {

    Serial.print(rtc.getDOWStr()); // Day
    Serial.print(" ");

    Serial.print(rtc.getDateStr()); // Date
    Serial.print(" -- ");

    Serial.println(rtc.getTimeStr()); // Time

    delay (1000);
}
