#ifndef SERIAL_DEBUG_H_INCLUDED
#define SERIAL_DEBUG_H_INCLUDED

#if defined (ESP8266)
#define CHIP_NAME "ESP8266"
#elif defined (ESP32)
#define CHIP_NAME "ESP32"
#else
#error "This ain't an ESP8266 or ESP32"
#endif

class SerialDebug {
private:
    bool debug_enable_;

public:
    
    SerialDebug(bool enable);

    
    void printd(String message);
    void printi(String message);
    void printw(String message);
    void printe(String message);

    
    void printMacAddress(uint8_t *mac_addr);

    
    void begin(unsigned long time_to_wait = 3000, String chipName = CHIP_NAME);
};

#endif 
