# activateRelayWithMicrophone

This project intends to activate/deactivate a relay by listening to a sound sensor (with microphone). Commands will be triggered through claps.

#### Requirements

1 Arduino  
1 relay (5 volts - 1 channel)  
1 Sensitivity Sound Detection Module (tested with KY-038)  
Cables to connect relay to electric current and the device to be switched on/off.

##### Important: maximum electric current supported by simple relays is up to 10 A (amps).

#### How it works

The sound module should be connected on port 10 and relay on port 9 (although both of them can be changed via code).  
The number of claps to trigger events is 2 and also can be modified in the code ('requiredClaps' variable).  
The circuit is closed when relay state is on LOW and opened on HIGH.
