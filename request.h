#pragma once
#include <random>
#include <string>
#include <iostream>

using std::string;

/**
 * @class Request
 * @brief A class representing a request to a web server
 */
class Request {
  public:
    /**
     * @brief Constructs a new request with random time, in and out values
     */
    Request() { time = generateTime(); in = generateRandomIpAddress(); out = generateRandomIpAddress(); };
    int time;  //!< The time required to process the request
    string in; //!< The IP address of the client making the request
    string out; //!< The IP address of the server to which the request is being sent
  private:
    /**
     * @brief Generates a random IP address
     * This function was written using ChatGPT
     * @return A string representing the generated IP address
     */
    string generateRandomIpAddress() {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dis(0, 255);
      return std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen)) + "." + std::to_string(dis(gen));
    };
    /**
     * @brief Generates a random "time" value in the range [2, 50)
     * This function was written using ChatGPT
     * @return The generated time value
     */
    int generateTime() {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_int_distribution<> dist(2, 50);
      return dist(gen);
    };

};

