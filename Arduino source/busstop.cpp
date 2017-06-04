/*
  TKL Bus stop data parsers
  Gets data from public REST API,
  and parses arrival times for lines coming in to bus stop
  Ketturi Fox 2017
*/

#include <Arduino.h>
#include "busstop.h"

BusStop::BusStop(const char* stopnum) { //Set stop number
  strcpy(path, resource); //Parse reguest string for stop
  strcat(path, stopnum);
  strcpy(BusStopNumber, stopnum);
}

void BusStop::updateBuffer(void) { //Send GET and parse json when called
  RestClient client = RestClient(server);  //Maybe should be initialized some where else, I don't know where...

  client.get(path, &jsonData); //Get resource from web server, return json data

  DynamicJsonBuffer buffer(4000); //Must be large enough to parse all data

  JsonObject& root = buffer.parse(jsonData);
  JsonArray& data = root["body"][BusStopNumber]; //Bus data is stored in JSON array

  arrivalBuffer.clear(); //Clear old data from buffer

  for (std::size_t i = 0; i < data.size(); i++) {
    JsonObject& entry = data[i];

    const char* lineRef = entry["lineRef"];
    const char* expectedArrivalTime = entry["call"]["expectedArrivalTime"];

    arrivalBuffer.insert(lineRef, expectedArrivalTime); //Store pared JSON data to accessible array
  }
}



