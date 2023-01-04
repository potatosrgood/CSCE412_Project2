#pragma once

#include <queue>
#include <vector>
#include "request.h"
#include "WebServer.h"

class LoadBalancer {
  public:
    LoadBalancer() {}
    void performCycle();
    bool hasItems() { return !requests.empty() };
    int getTime() { return clockTime; };
    void addRequest(Request newreq) { requests.push(newreq); };
  private:
    queue<Request> requests;
    vector<WebServer> servers;
    int clockTime;
}
