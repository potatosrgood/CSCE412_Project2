#pragma once
#include <random>
#include <string>

using std::string;

class Request {
  public:
    Request() { time = generateTime(); string in = generateRandomIpAddress(); string out = generateRandomIpAddress(); };
    int time;
    string in;
    string out;
  private:
    string generateRandomIpAddress() {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dis(0, 255);
      return std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen));
    };
    int generateTime() {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dist(0, 50);
      return dist(gen);
    };

};

