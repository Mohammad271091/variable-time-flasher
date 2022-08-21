#include "Flasher.h";

// Constructor
Flasher::Flasher(int pin, unsigned long on_time, unsigned long off_time)
{

    pinMode(pin, OUTPUT);
    _pin = pin;
    _on_time = on_time;
    _off_time = off_time;
}

void Flasher::start()
{
    flasher_on = true;
}

void Flasher::loop()
{
    if (flasher_on == true)
    {
        flash();
    }
    else
    {
        return;
    }
}

// flasher
bool Flasher::flash()
{

    if (ledstate == HIGH)
    {
        if ((millis() - rememberTime) >= _on_time)
        {
            ledstate = LOW;          // change the state of LED
            rememberTime = millis(); // remember Current millis() time
        }
    }
    else
    {
        if ((millis() - rememberTime) >= _off_time)
        {
            ledstate = HIGH;         // change the state of LED
            rememberTime = millis(); // remember Current millis() time
        }
    }

    digitalWrite(_pin, ledstate); // turn the LED ON or OFF}
}

// Destructor
Flasher::~Flasher(){};

// Stop flasher
void Flasher::stop()
{
    flasher_on = false;
}