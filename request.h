#pragma once
#include <random>
#include <string>
#include <iostream>

using std::string;

class Request {
  public:
    Request() { time = generateTime(); in = generateRandomIpAddress(); out = generateRandomIpAddress(); };
    int time;
    string in;
    string out;
  private:
    // generates a random ip address string
    // created by ChatGPT
    string generateRandomIpAddress() {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dis(0, 255);
      return std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen));
    };
    // generates a random time
    // created by ChatGPT
    int generateTime() {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dist(2, 50);
      return dist(gen);
    };

};

