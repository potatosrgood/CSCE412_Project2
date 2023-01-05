#include "LoadBalancer.h"

LoadBalancer::LoadBalancer (int serverCount) {
  for(int i = 0; i < serverCount; ++i) {
    servers.emplace_back();
  }
  clockTime = 0;
  serversDone = false;
}

void LoadBalancer::performCycle() {
  bool hasRunning = false;
  for(int i = 0; i < servers.size(); i++) {
    bool res = servers[i].iterate();
    if(res) {
      if(servers[i].timeLeft == 0) {
        cout << "Server " << i << " has completed a task" << endl;
      }
      if(!requests.empty()) {
        cout << "Web server number " << i << " is starting a new task" << endl;
        servers[i].startNewRequest(requests.front());
        requests.pop();
        hasRunning = true;
      }
    } else {
      hasRunning = true;
    }
  }
  if(!hasRunning) {
    serversDone = true;
  }
}

void LoadBalancer::validator() {
  for(int i = 0; i < servers.size(); i++) {
    cout << servers[i].timeLeft << endl;
  }
  cout << "queue items remaining " << requests.size() << endl;
}
