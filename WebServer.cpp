#include "WebServer.h"

bool WebServer::iterate() {
  timeLeft--;
  return (timeLeft <= 0) ? true : false;
}

void WebServer::startNewRequest(Request r) {
  currentRequest = r;
  timeLeft = r.time;
}
