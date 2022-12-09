#ifndef TRUCK_H
#define TRUCK_H
#include <string>
#include "ecs36b_Common.h"
#include "Automobile.h"
using namespace std;

class Truck : public Automobile {
    private:   
        string name;

    public:

        Truck(string n);

        Truck();

        void setName(string n);

        string getName();
};
#endif