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
    myMotorcycle.setID(2);
    myMotorcycle.setModel("Yamaha");
    myMotorcycle.setSize("Small");
    myMotorcycle.setCargo("None");
    myMotorcycle.setCargoValue(0);
    myMotorcycle.setPassengers(2);
    myMotorcycle.setHelmet(true);
    myMotorcycle.setSafetyRating(3);
    myMotorcycle.calculate();
    cout << "Right  Motorcycle Information:" << endl << myMotorcycle.dump2JSON().toStyledString() << endl;

    // Run Left Motorcycle Server
    HttpServer httpserver(7375);
    Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2, "Right Motorcycle");
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
        // Send Right Motorcycle info to car
        if (s.Car_Map[it->first]->getWarning() == "Crashing") {
            try {
            myv = myClient.move("move", "Motorcycle",
                    myMotorcycle.dump2JSON(),
                    gps,
                    "Right Motorcycle");
            cout << "Sending Right Motorcycle Info back to Car Server..." << endl;
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