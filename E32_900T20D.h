#ifndef E32_900T20D_H
#define E32_900T20D_H

#include "Arduino.h"

class E32_900T20D {

public:
    E32_900T20D(uint8_t rxPin, uint8_t txPin);
    bool begin();
    ResponseStatus sendMessage(String message);
    ResponseContainer receiveMessage();
};

#endif
