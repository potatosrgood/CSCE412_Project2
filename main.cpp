#include <iostream>
#include <queue>
#include "LoadBalancer.h"

using namespace std;


int NUM_WEBSERVERS = 50;
int MAX_REQUEST_LENGTH = 100;

int main(){
  cout << "Driver" << endl;
  LoadBalancer loadb(10);
  for(int i = 0; i < 20; i++) {
    Request t_req;
    loadb.addRequest(t_req);
  }
  cout << "Created a load balancer with 100 requests and 10 web servers" << endl;
  cout << "launching" << endl;
  while(loadb.hasItems()) {
    cout << "At time: " << loadb.getTime() << endl;
    loadb.performCycle();
    loadb.incTime();
  }
  cout << "run success" << endl;
  cout << "validating remaining run time" << endl;
  loadb.validator();
  return 1;
}
