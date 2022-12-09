#ifndef Car_H
#define Car_H
#include <string>
#include "ecs36b_Common.h"
#include "Automobile.h"
using namespace std;

class Car : public Automobile {
    private:   
        string name;

    public:

        Car(string n);

        Car();

        void setName(string n);

        string getName();

        void calculate();
};
#endif