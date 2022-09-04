#include "Flasher.h";

// Constructor
Flasher::Flasher(int pin, unsigned long on_time, unsigned long off_time, resolution res)
{
    this->res = res;

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
        flash();
    else
        return;
}

// flasher
bool Flasher::flash()
{

    if (res == MILLIS)

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
    }

    else if (res == MICROS)
    {
        if (ledstate == HIGH)
        {
            if ((micros() - rememberTime) >= _on_time)
            {
                ledstate = LOW;
                rememberTime = micros();
            }
        }
        else
        {
            if ((micros() - rememberTime) >= _off_time)
            {
                ledstate = HIGH;
                rememberTime = micros();
            }
        }
    }

    else if (res == SECONDS)
    {
        if (ledstate == HIGH)
        {
            if ((millis()/1000 - rememberTime) >= _on_time)
            {
                ledstate = LOW;
                rememberTime = millis()/1000;
            }
        }
        else
        {
            if ((millis()/1000 - rememberTime) >= _off_time)
            {
                ledstate = HIGH;
                rememberTime = millis()/1000;
            }
        }
    }

    digitalWrite(_pin, ledstate); // turn the LED ON or OFF
}

// Destructor
Flasher::~Flasher(){};

// Stop flasher
void Flasher::stop()
{
    flasher_on = false;
}