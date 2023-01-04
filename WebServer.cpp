#include "Request.h" // Include the header file for the Request class

class WebServer{
public:
    int timeLeft = -1;
    Request currentRequest;

    WebServer(){
    }
    void startNewRequest(Request r){
        currentRequest = r;
        timeLeft = r.time;
    }
    void iterate(){
        timeLeft--;
    }

};
