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
    /**
     * @brief Checks if all the servers are idle
     */
    bool hasItems() { return !serversDone; };
    /**
     * @brief gets the clock getTime
     * @return the clock time
     */
    int getTime() { return clockTime; };
    /**
     * @brief increments clock time by 1
     */
    void incTime() { clockTime++; };
    /**
     * @brief Adds a new request to the load balancer
     * @param newreq the new request to be added
     */
    void addRequest(Request newreq) { requests.push(newreq); };
    /**
     * @brief checks current state of load balancer
     */
    void validator();
    queue<Request> requests; //!< the queue of requests for the servers
    vector<WebServer> servers; //!< stores the servers the load balancer is responsible for
    int clockTime; //!< the current clock time, stored as an integer
    bool serversDone; //!< boolean representing the state of the servers. true if all of them are done
};
