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

/**
 * @class LoadBalancer
 * @brief A class representing a load balancer that distributes requests to a pool of web servers
 */
class LoadBalancer {
  public:
    /**
     * @brief Constructs a new load balancer with the given number of servers
     * @param serverCount The number of servers to create
     */
    LoadBalancer(int serverCount);

    /**
     * @brief Performs a single clock cycle for the load balancer
     *
     * This function iterates through all the servers and checks if any of them
     * have completed their current task. If a server is available, it will start
     * processing the next request in the queue. If no servers are available and
     * the request queue is empty, it sets the `serversDone` flag to true.
     */
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
