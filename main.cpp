#include <iostream>
#include <queue>
#include "LoadBalancer.h"
#include <stdio.h>
#include <random>

using namespace std;

/**
 * @brief Generates a random number in the range specified by low and high with a uniform distribution
 * @param low an integer for the lowest number of the range inclusive
 * @param high an integer for the highest number of the range inclusive
 * @return The generated number
 */
int randomChance(int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

/**
 * @brief Generates a random number with the exponential distribution with our given lambda
 * @param lambda the lambda for the exponential distribution
 * @return The generated number
 */
int randomFewer(double lambda) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<> dist(lambda);
    return dist(gen);
}

/**
 * @brief The main program entry point, creates and runs a load balancer for the given run duration
 * @param argc The number of command-line arguments
 * @param argv The command-line arguments, server count, request count, and run duration
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
