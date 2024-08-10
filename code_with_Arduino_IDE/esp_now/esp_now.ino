#include <esp_now.h>
#include <WiFi.h>

#define debug_ true

// For debug 
void debug_print(String message) {
    if (debug_) {

        Serial.println("[DEBUG]:\t" + message);
    }
}

/*

        This code can send and receive messages of others devices. You can add
    a new peer sending the MAC Address in the Serial (115200). 

*/


void setup() {

    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    debug_print("MY MAC ADDRESS -> " + String(WiFi.macAddress()));

}


void loop() {

    delay(1000);
    debug_print("Device alive");


}