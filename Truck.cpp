#include <string>
#include "Truck.h"

using namespace std;

Truck::Truck(string n) {
    this->name = n;
}

Truck::Truck() {
    this->name = "";
}

void Truck::setName(string n) {this->name = n;}

string Truck::getName() {return this->name;}