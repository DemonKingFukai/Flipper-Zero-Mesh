#include "E32_900T20D_Plugin.h"

E32_900T20D_Plugin::E32_900T20D_Plugin(uint8_t rxPin, uint8_t txPin) : e32(rxPin, txPin) {}

bool E32_900T20D_Plugin::begin() {
return e32.begin();
}

bool E32_900T20D_Plugin::handleRequest(FlipperConnectionRequest* request) {
if (request->getMethod() == "sendMessage") {
// get the message to send from the request
String message = request->getString("message");
// send the message using the E32_900T20D module
ResponseStatus rs = e32.sendMessage(message);
// set the response status based on the result of sendMessage
request->setResponseStatus(rs.code, rs.getResponseDescription());
return true;
}
else if (request->getMethod() == "receiveMessage") {
// receive a message using the E32_900T20D module
ResponseContainer rc = e32.receiveMessage();
// set the response data based on the result of receiveMessage
request->setResponseData(rc.data);
request->setResponseStatus(rc.status.code, rc.status.getResponseDescription());
return true;
}
// if the request method is not "sendMessage" or "receiveMessage", return false
return false;
}
