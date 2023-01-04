#include <iostream>
#include <queue>
#include "LoadBalancer.h"

using namespace std;


int NUM_WEBSERVERS = 50;
int MAX_REQUEST_LENGTH = 100;

int main(){
  cout << "Driver" << endl;
  LoadBalancer loadb(10);
  for(int i = 0; i < 100; i++) {
    Request t_req;
    loadb.addRequest(t_req);
  }
  cout << "Created a load balancer with 100 requests and 10 web servers" << endl;
  cout << "launching" << endl;
  loadb.launch();
  cout << "run success" << endl;
  return 1;
}
