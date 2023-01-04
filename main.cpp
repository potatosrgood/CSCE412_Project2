#include <iostream>
#include <queue>

using namespace std;


#define NUM_WEBSERVERS 50
#define MAX_REQUEST_LENGTH 100


struct Request {
    int time;
    string in;
    string out;
};

Request createRequest(){

}


int main(){
    //create a list of webservers
    Webserver* webservers = Webserver[50]();
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