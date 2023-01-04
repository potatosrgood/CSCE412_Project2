#include "LoadBalancer.h"

LoadBalancer::LoadBalancer (int serverCount) {
  for(int i : serverCount) {
    servers.emplace_back();
  }
  clockTime = 0;
}

void LoadBalancer::performCycle() {
  for(int i = 0; i < servers.size(); i++) {
    bool res = servers[i].iterate();
    if(res) {
      servers[i].startNewRequest(requests.front());
      requests.pop()
    }
    if(requests.empty()) {
      break;
    }
  }
}

void LoadBalancer::launch() {
  while(hasItems()) {
    performCycle();
    ++clockTime;
  }
}
