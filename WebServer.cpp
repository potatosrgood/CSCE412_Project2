#include "WebServer.h"
#include <iostream>

using std::cout;
using std::endl;

/**
 * @brief Decrements the time left for the current task and checks if it has completed
 * @return True if the task has completed, false otherwise
 */
bool WebServer::iterate() {
  timeLeft--;
  if(timeLeft < 0) {
    timeLeft = -1;
  }
  return timeLeft <= 0;
}
/**
 * @brief Starts a new task with the given request
 * @param r The request to start processing
 */
void WebServer::startNewRequest(Request r) {
  //cout << "Server has recieved request from " << r.in << " to " << r.out << " with time to complete of " << r.time << endl;
  currentRequest = r;
  timeLeft = r.time;
}
