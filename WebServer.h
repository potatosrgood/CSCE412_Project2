#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "request.h" // Include the header file for the Request class
/**
 * @class WebServer
 * @brief A class representing a web server
 */
class WebServer {
 public:
  int timeLeft = -1; //!< The time remaining for the current task (-1 if no task is being processed)
  Request currentRequest; //!< The request currently being processed

  
  WebServer() {}
  void startNewRequest(Request r);
  bool iterate();
};

#endif
