#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "Request.h" // Include the header file for the Request class

class WebServer {
 public:
  int timeLeft = -1;
  Request currentRequest;

  WebServer() {}
  void startNewRequest(Request r);
  bool iterate();
};

#endif
