#include <iostream>
#include <queue>
#include "LoadBalancer.h"
#include <stdio.h>
#include <random>

using namespace std;

/**
 * @brief The number of web servers to create
 */
int NUM_WEBSERVERS = 50;
/**
 * @brief The maximum length of a request
 */
int MAX_REQUEST_LENGTH = 100;

/**
 * @brief Generates a random number in the range [0, 5]
 * @return The generated number
 */
int randomChance(int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

int randomFewer(double lambda) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> dist(lambda);
    return dist(gen);
}
/**
 * @brief The main program entry point
 * @param argc The number of command-line arguments
 * @param argv The command-line arguments
 * @return The exit status of the program (1 for success, 0 for failure)
 */
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
    if(randomChance(0, randomChance(3, 8)) == 0) {
      int newReqs = randomFewer(1.0)+1;
      cout << newReqs << " new request(s)" << endl;
      while(newReqs > 0) {
        Request t_req;
        loadb.addRequest(t_req);
        --newReqs;
      }
    }
    loadb.performCycle();
    loadb.incTime();
  }
  cout << "run success" << endl;
  cout << "validating remaining run time" << endl;
  loadb.validator();
  return 1;
}
