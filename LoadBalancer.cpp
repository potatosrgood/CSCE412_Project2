#include "LoadBalancer.h"

LoadBalancer::LoadBalancer (int serverCount) {
  for(int i = 0; i < serverCount; ++i) {
    servers.emplace_back();
  }
  clockTime = 0;
}

void LoadBalancer::performCycle() {
  for(int i = 0; i < servers.size(); i++) {
    bool res = servers[i].iterate();
    if(res) {
      cout << "Web server number " << i << " is starting a new task" << endl;
      servers[i].startNewRequest(requests.front());
      requests.pop();
    }
    if(requests.empty()) {
      break;
    }
  }
}

void LoadBalancer::launch() {
  while(hasItems()) {
    cout << "At time: " << clockTime << endl;
    performCycle();
    ++clockTime;
  }
}
