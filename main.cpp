#include <iostream>
#include <queue>
#include "request.h"

using namespace std;


int NUM_WEBSERVERS = 50
int MAX_REQUEST_LENGTH = 100

int main(){
    //create a list of webservers
    WebServer* webservers = Webserver[50]();
    //create a queue of requests
    queue<Request> requestqueue;
    for(int i=0; i<NUM_WEBSERVERS*20; i++){

    }

    //loop that keeps going till both queue is empty and all webservers are not busy
    int clockCycle = 0;
    while true{
        //loop thru webservers and give request to those not busy

        //iterate every webserver by one clock cycle

        //move onto next clock cycle
        clockCycle++;
    }

    return 1;
}
