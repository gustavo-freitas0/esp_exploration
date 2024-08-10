#if defined (ESP8266)
#define CHIP_NAME "ESP8266"
#elif defined (ESP32)
#define CHIP_NAME "ESP32"
#else
#error "This ain't an ESP8266 or ESP32"
#endif

#include "SerialDebug.h"

SerialDebug::SerialDebug(bool enable) : debug_enable_(enable) {}

void SerialDebug::printd(String message) {
    if (debug_enable_) {
        Serial.print("[DEBUG] :\t");
        Serial.println(message);
    }
}

void SerialDebug::printi(String message) {
    if (debug_enable_) {
        Serial.print("[INFO] :\t");
        Serial.println(message);
    }
}

void SerialDebug::printw(String message) {
    if (debug_enable_) {
        Serial.print("[WARNING] :\t");
        Serial.println(message);
    }
}

void SerialDebug::printe(String message) {
    if (debug_enable_) {
        Serial.print("[ERROR] :\t");
        Serial.println(message);
    }
}

void SerialDebug::printMacAddress(uint8_t *mac_addr) {
    if (debug_enable_) {
        Serial.print("[MAC ADDR] :");
        for (int i = 0; i < 6; i++) {
            if (i > 0) Serial.print(":");
            Serial.print(String(mac_addr[i], HEX));
        }
        Serial.println();
    }
}

void SerialDebug::begin(unsigned long time_to_wait, String chipName) {
    if (debug_enable_) {
        while (!Serial) {
            ; 
        }
        delay(time_to_wait); 
        Serial.println("\n------------------------------- " + chipName + " STARTED -------------------------------\n");
    }
}
