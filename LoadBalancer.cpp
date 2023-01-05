#include "LoadBalancer.h"
/**
 * @brief Constructs a new load balancer with the given number of servers
 * @param serverCount The number of servers to create
 */
LoadBalancer::LoadBalancer (int serverCount) {
  for(int i = 0; i < serverCount; ++i) {
    servers.emplace_back();
  }
  clockTime = 0;
  serversDone = false;
}
/**
 * @brief Performs a single clock cycle for the load balancer
 *
 * This function iterates through all the servers and checks if any of them
 * have completed their current task. If a server is available, it will start
 * processing the next request in the queue. If no servers are available and
 * the request queue is empty, it sets the `serversDone` flag to true. If there
 * are no tasks and a server is done, then the server sits idle waiting.
 */
void LoadBalancer::performCycle() {
  unsigned short numActive = 1;
  for(int i = 0; i < servers.size(); i++) {
    bool res = servers[i].iterate();
    if(res) {
      if(servers[i].timeLeft == 0) {
        numActive--;
        //cout << "Server " << i << " has completed a task" << endl;
      }
      if(!requests.empty()) {
        //cout << "Web server number " << i << " is starting a new task" << endl;
        servers[i].startNewRequest(requests.front());
        requests.pop();
        numActive++;
      }
    }
  }
  if(numActive==0) {
    serversDone = true;
  }
}
/**
 * @brief Queries the servers and checks the time remaining for them to complete their tasks. Then checks how many requests are in the queue.
 */
void LoadBalancer::validator() {
  for(int i = 0; i < servers.size(); i++) {
    cout << servers[i].timeLeft << endl;
  }
  cout << "queue items remaining " << requests.size() << endl;
}
