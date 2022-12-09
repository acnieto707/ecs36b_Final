#include <string>
#include "Motorcycle.h"

using namespace std;

Motorcycle::Motorcycle(string n, bool h) {
    this->name = n;
    this->hasHelmet = h;
}

Motorcycle::Motorcycle() {
    this->name = "";
    this->hasHelmet = false;
}

void Motorcycle::setName(string n) {this->name = n;}

string Motorcycle::getName() {return this->name;}

void Motorcycle::setHelmet(bool h) {this->hasHelmet = h;}

bool Motorcycle::getHelmet() {return this->hasHelmet;}

void Motorcycle::calculate() {
    
    double dValue = (this->getPassengers() * 5) + this->getCargoValue();
    this->setValue(dValue);

    double dSurvive = 10 + (this->getSafetyRating() * 2);
    if (this->getHelmet()) { dSurvive++;}
    this->setSurvivability(dSurvive);

    double dScore = this->getSurvivability() - this->getValue();
    this->setCollisionScore(dScore);
}