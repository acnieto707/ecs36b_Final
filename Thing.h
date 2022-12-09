#ifndef THING_H
#define THING_H
#include <string>
#include "ecs36b_Common.h"

using namespace std;

class Thing {
    private:   
        string obj;

    public:
        Thing(string n);

        Thing();

        void setObj(string n);

        string getObj();

        Json::Value dump2JSON();

        bool JSON2Object(Json::Value);
};
#endif