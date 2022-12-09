#ifndef Motorcycle_H
#define Motorcycle_H
#include <string>
#include "ecs36b_Common.h"
#include "Automobile.h"
using namespace std;

class Motorcycle : public Automobile {
    private:   
        string name;
        bool hasHelmet;

    public:

        Motorcycle(string n, bool h);

        Motorcycle();

        void setName(string n);

        string getName();

        void setHelmet(bool h);

        bool getHelmet();

        void calculate();
};
#endif