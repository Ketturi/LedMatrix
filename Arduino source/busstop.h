/*
  TKL Bus stop data parsers
  Gets data from public REST API,
  and parses arrival times for lines coming in to bus stop
  Ketturi Fox 2017
*/

#include <Arduino.h>

#include <ArduinoJson.h>
#include "RestClient.h"

#include "arrival_buffer.hpp" //Helper for storing data in array

class BusStop
{
  public:
    BusStop(const char* stopnum); //sets bus stop that is monitored

    void updateBuffer(void); //Downloads bus stop data by REST api from internet and stores it.

    String getStopNumber() { //Return monitored stop number
      return BusStopNumber;
    }

    int bufferSize() const { //Return current count of arrivals stored in buffer
      return arrivalBuffer.size();
    }

    String returnLine(unsigned int i) const {
      return arrivalBuffer[i].line();
    }

    String returnTime(unsigned int i) const {
      return arrivalBuffer[i].time();
    }

  private:
    ArrivalBuffer arrivalBuffer;

    const char* server = "data.itsfactory.fi";  // TKL bus rest api server's address
    const char* resource = "/journeys/api/1/stop-monitoring?stops="; // http resource for stop monitoring
    char BusStopNumber[5];                 // Stop number that class watches

    char path[43]; //Path that is parsed from resource path and stop number

    String jsonData; 
};


