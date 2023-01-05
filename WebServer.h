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

  /**
   * @brief Constructs a new web server
   */
  WebServer() {}
  /**
   * @brief Starts a new task with the given request
   * @param r The request to start processing
   */
  void startNewRequest(Request r);
  /**
   * @brief Decrements the time left for the current task and checks if it has completed
   * @return True if the task has completed, false otherwise
   */
  bool iterate();
};

#endif
