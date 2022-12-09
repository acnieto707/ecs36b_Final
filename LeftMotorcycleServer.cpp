// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include <time.h>
#include "hw5server.cpp"
#include "hw5client.h"

using namespace jsonrpc;
using namespace std;

int main() {
    // Create Initial Objects
    Motorcycle myMotorcycle;
    myMotorcycle.setID(1);
    myMotorcycle.setModel("Honda");
    myMotorcycle.setSize("Small");
    myMotorcycle.setCargo("Backpack");
    myMotorcycle.setCargoValue(3);
    myMotorcycle.setPassengers(1);
    myMotorcycle.setHelmet(false);
    myMotorcycle.setSafetyRating(4.5);
    myMotorcycle.calculate();
    cout << "Left Motorcycle Information:" << endl << myMotorcycle.dump2JSON().toStyledString() << endl;

    // Run Left Motorcycle Server
    HttpServer httpserver(7374);
    Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2, "Left Motorcycle");
    while (!s.isDone) {
        s.StartListening();
    }

    // Client for Car
    HttpClient httpclient("http://127.0.0.1:7373");
    hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value myv;
    Json::Value gps;
    gps["location"] = "car";

    // Access everything in Car map
    for (auto it = s.Car_Map.begin(); it != s.Car_Map.end(); it++) {
        // Send Left Motorcycle info to car
        if (s.Car_Map[it->first]->getWarning() == "Crashing") {
            try {
            myv = myClient.move("move", "Motorcycle",
                    myMotorcycle.dump2JSON(),
                    gps,
                    "Left Motorcycle");
            cout << "Sending Left Motorcycle Info  back to Car Server..." << endl;
            } catch (JsonRpcException &e) {
            cerr << e.what() << endl;
            }
        }
    }

    // Run when done moving objects
    Json::Value done;
    try {
    done = myClient.end();
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }

    // Wait for character input to stop server
    cout << "Press enter to stop server" << endl;
    getchar();
    s.StopListening();

    return 0;
}