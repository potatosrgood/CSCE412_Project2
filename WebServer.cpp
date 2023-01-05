#include "WebServer.h"
#include <iostream>

using std::cout;
using std::endl;

bool WebServer::iterate() {
  timeLeft--;
  if(timeLeft == 0) {
    cout << "Server has completed a task" << endl;
  }
  if(timeLeft < 0) {
    timeLeft = -1;
  }
  return timeLeft <= 0;
}

void WebServer::startNewRequest(Request r) {
  cout << "Server has recieved request from " << r.in << " to " << r.out << " with time to complete of " << r.time << endl;
  currentRequest = r;
  timeLeft = r.time;
}
