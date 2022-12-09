#include <string>
#include "Person.h"
using namespace std;

Person::Person(string n) {
    this->name = n;
}

Person::Person() {
    this->name = "";
}

void Person::setName(string n) {this->name = n;}

string Person::getName() {return this->name;}

Json::Value
Person:: dump2JSON
() {
    Json::Value result {};
    result["name"] = this->name;
    return result;
}

bool Person::JSON2Object(Json::Value arg) {
    this->name = (arg["name"]).asString();
    return true;
}