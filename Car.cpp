#include <string>
#include "Car.h"

using namespace std;

Car::Car(string n) {
    this->name = n;
}

Car::Car() {
    this->name = "";
}

void Car::setName(string n) {this->name = n;}

string Car::getName() {return this->name;}

void Car::calculate() {

    double dValue = (this->getPassengers() * 5) + this->getCargoValue();
    this->setValue(dValue);

    double dSurvive = 15 + (this->getSafetyRating() * 2);
    this->setSurvivability(dSurvive);

    double dScore = this->getSurvivability() - this->getValue();
    this->setCollisionScore(dScore);
}