#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 255);
uniform_int_distribution<> dist(0, 50);

string generateRandomIpAddress() {
  return std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen));
}

struct Request {
    
    int time = dist(gen);
    string in = generateRandomIpAddress();
    string out = generateRandomIpAddress();

};

