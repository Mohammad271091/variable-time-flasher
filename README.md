# Flasher (Arduino flasher library with variable on/off time)

The Flasher Arduino library is the best abstraction to use when you want to blink an LED (or any other digital device)
with variable on and off times.
Different on/off times may indicate different situations; for example, longer off time than on time may indicate the device is on and working.
equal on/off times may indicate the device is in standby mode, and so forth. 

- You can use it with Arduino, ESP8266, ESP-32 and all relevant devices.


## Installation

1. Download/clone the master branch of this repository: (https://github.com/Mohammad271091/variable-time-flasher.git)
2. Move the folder on your Library folder (On your `Libraries` folder inside Sketchbooks or Arduino software).
3. Make sure to rename the folder to "Flasher"


## How to use

First, you need to include the library into your sketch

```cpp
#include <Flasher.h>
```

Then, create an instance of **Flasher** class with the parameters:
- pin : the pin number of the LED/device.
- on_time : how long the LED should remain at on state.
- off time : how long the LED should remain at off state.

```cpp
Flasher my_led(pin, on_time, off_time);
```

then in Setup() section, you need to invoke the function start(), since the flasher is off by default.

```cpp
my_led.start();
```

*note: you do NOT need to set the pinMODE(pin, OUTPUT) in the setup section since it is set by default inside the library logic.*

Finally, you should call the loop() function inside the Arduino loop():

```cpp
my_led.loop();
```

Now, the LED/device is flashing according to your settings!.

*if you want to stop it at any condition, you only need to call the stop() method:*
```cpp
my_led.stop();
```


## Example 

here's a simple example only to demonstrate the correct use of the library object and methods.
a potentiometer connected to A0 pin of Arduino Nano controlling the flash action of the built in LED.
*please read the comments in the code:* 

```cpp
// call the flasher library
#include <Flasher.h>

// create an instance of Flasher class, use the built in LED, flash for: 120ms on, 1500ms off 
Flasher myled(LED_BUILTIN, 120, 1500);

void setup()
{
    // serial communication, baud rate at 115200bps
    Serial.begin(115200);
    // connect a potentiometer at analog pin A0
    pinMode(A0, INPUT);
    // call the start method 'insde void setup()'
    myled.start();
}

void loop()
{
    // call the loop method 'inside void loop()'
    myled.loop();

    // print the potentiometer reading on the serial monitor
    Serial.println(analogRead(A0));

    // if the potentiometer reading is below 500 (out of 1024 for Nano/Uno/Micro/Leonardo/Mega/Mini/etc... or any board with 10-bit analog input) then:
    if ( analogRead(A0) < 500 )
    {
        //stop flashing
        myled.stop();
    }
    else{
        //or otherwise, start flashing!
        myled.start();
    }
    
}
```


## DISCLAIMER

If you use delay() function in any part of your code, the library will **NOT** work, instead, use the library itself!, or use millis() core function.


## Documentation

### Constructor

```cpp
Flasher::Flasher(int pin, unsigned long on_time, unsigned long off_time)
```

**Example:**
```cpp
//flash LED 6 with 1 second on, 1 second off
Flasher myled(6, 1000, 1000); 

//flash the built-in LED for 120ms on, 1.5s off
Flasher myled(LED_BUILTIN, 120, 1500);

//flashe LED 10 with 2 seconds on, half second off
Flasher myled(10, 2000, 500);
```

### Destructor

```cpp
Flasher::~Flasher()
```
Destructor of the Flasher instance

## Class Medthods

### Flasher start

should be called in setup() & can be called in loop() in case the flasher stopped and you'd like to run it again

```cpp
void Flasher::start();
```

### Flasher stop

```cpp
void Flasher::stop();
```

### Flasher loop

should be called in arduino main loop(), it basically checks for the user's desired action (start or stop) in real-time and updates the flash function accordingly

```cpp
void Flasher::loop();
```

### Flasher flash

this is a built-in boolean method to be used within the library to perform the flashing logic

```cpp
bool Flasher::flash();
```


