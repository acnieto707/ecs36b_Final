#include <string>
#include "Thing.h"
using namespace std;

Thing::Thing(string n) {this->obj = n;}

Thing::Thing() {this->obj = "";}

void Thing::setObj(string n) {this->obj = n;}

string Thing::getObj() {return this->obj;}

Json::Value
Thing:: dump2JSON
() {
    Json::Value result {};
    result["obj"] = this->obj;
    return result;
}

bool Thing::JSON2Object(Json::Value arg) {
    this->obj = (arg["obj"]).asString();
    return true;
}