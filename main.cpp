#include <iostream>
#include <queue>
#include "request.h"
#include "LoadBalancer.h"

using namespace std;


int NUM_WEBSERVERS = 50
int MAX_REQUEST_LENGTH = 100

int main(){
  LoadBalancer loadb();
  loadb.launch();
  return 1;
}
