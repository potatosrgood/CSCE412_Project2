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
    void launch();
    bool hasItems() { return !requests.empty(); };
    int getTime() { return clockTime; };
    void addRequest(Request newreq) { requests.push(newreq); };
  private:
    queue<Request> requests;
    vector<WebServer> servers;
    int clockTime;
};
