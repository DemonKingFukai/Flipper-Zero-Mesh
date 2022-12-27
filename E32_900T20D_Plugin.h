#include "FlipperPlugin.h"
#include "E32_900T20D.h"

class E32_900T20D_Plugin : public FlipperPlugin {

private:
    E32_900T20D e32;

public:
    E32_900T20D_Plugin(uint8_t rxPin, uint8_t txPin) : e32(rxPin, txPin) {}

    bool begin();
    bool handleRequest(FlipperConnectionRequest* request);
};
