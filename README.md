### Using MTS Dragonfly to receive texts ###

I've written a [cellular networking driver](https://github.com/ARMmbed/mtsas-driver) for the [Multitech Dragonfly board](https://developer.mbed.org/platforms/MTS-Dragonfly/) using mbed-os. 

This is a quick example of a receiving text messages on an Multitech Dragonfly board. 

**NOTE**: This board has an activated SIM card registered with a cellular provider, so it has been assigned a phone number capable of receiving texts.

## How it works

The driver allows a callback to be attached when a text message is received. The implementation of this functionality can be seen [here](https://github.com/ARMmbed/mtsas-driver/blob/master/MTSASInterface.cpp#L393-L447). This is non-blocking, meaning you can use the device for other functionality while waiting for the text, and your callback will be invoked asynchronously. 

The [callback](https://github.com/sarahmarshy/dragonfly-text-printer/blob/master/main.cpp#L9-L12) I've [attached](https://github.com/sarahmarshy/dragonfly-text-printer/blob/master/main.cpp#L29) prints the message to the thermal printing shield, but this is defined at the application level, so it's flexible. 
