#ifndef Flasher_H
#define Flasher_H
#include "arduino.h"

class Flasher
{
public:
    Flasher(int pin, unsigned long on_time, unsigned long off_time);
    ~Flasher();
    void start();
    bool flash();
    void stop();
    void loop();

private:
    int ledstate = HIGH;
    int _pin;
    unsigned long _on_time, _off_time;
    // unsigned long _off_time;
    unsigned long rememberTime = 0;
    bool flasher_on = false;
};

#endif