#pragma once

#include <queue>
#include <vector>
#include "request.h"
#include "WebServer.h"

class LoadBalancer {
  public:
    LoadBalancer() {}
    void performCycle();
    int getTime();
  private:
    queue<Request> requests;
    vector<WebServer> servers;
    int clockTime;
}
