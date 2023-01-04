#include <iostream>
#include <queue>
#include "LoadBalancer.h"
#include <stdio.h>

using namespace std;


int NUM_WEBSERVERS = 50;
int MAX_REQUEST_LENGTH = 100;

int randomChance() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 5);
    return dist(gen);
}

int main(int argc, char **argv){
  cout << "Driver" << endl;
  if(argc < 4) {
    cout << "Invalid parameters" << endl;
    cout << "Usage: ./a.out <server count> <request count> <run duration>" << endl;
    return 0;
  }
  LoadBalancer loadb(atoi(argv[1]));
  for(int i = 0; i < atoi(argv[2]); i++) {
    Request t_req;
    loadb.addRequest(t_req);
  }
  cout << "Created a load balancer with 100 requests and 10 web servers" << endl;
  cout << "launching" << endl;
  while(loadb.hasItems() && loadb.getTime() < atoi(argv[3])) {
    cout << "At time: " << loadb.getTime() << endl;
    if(randomChance() == 0) {
      cout << "New request" << endl;
      Request t_req;
      loadb.addRequest(t_req);
    }
    loadb.performCycle();
    loadb.incTime();
  }
  cout << "run success" << endl;
  cout << "validating remaining run time" << endl;
  loadb.validator();
  return 1;
}
