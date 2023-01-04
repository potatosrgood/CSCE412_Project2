#pragma once

#include <queue>
#include <vector>
#include <iostream>
#include "request.h"
#include "WebServer.h"

using std::queue;
using std::vector; 
using std::cout;
using std::endl;

class LoadBalancer {
  public:
    LoadBalancer(int serverCount);
    void performCycle();
    bool hasItems() { return !serversDone; };
    int getTime() { return clockTime; };
    void incTime() { clockTime++; };
    void addRequest(Request newreq) { requests.push(newreq); };
    void validator();
  private:
    queue<Request> requests;
    vector<WebServer> servers;
    int clockTime;
    bool serversDone;
};
