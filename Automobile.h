#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
#include "ecs36b_Common.h"

using namespace std;

class Automobile {
    private:   
        int id;
        string model;
        string size;
        string warning;
        string cargo;
        int cargoValue;
        int passengers;
        double safetyRating;
        double value;
        double survivability;
        double collisionScore;

    public:

        Automobile(int i, string m, string si, string w, string c, int cv, int p, double s, double v, double sv, double col);

        Automobile();

        // Getters and Setters
        void setID(int i);
        void setModel(string m);
        void setSize(string si);
        void setWarning(string w);
        void setCargo(string c);
        void setCargoValue(int cv);
        void setPassengers(int p);
        void setSafetyRating(double s);
        void setValue(double v);
        void setSurvivability(double sv);
        void setCollisionScore(double c);

        int getID();
        string getModel();
        string getSize();
        string getWarning();
        string getCargo();
        int getCargoValue();
        int getPassengers();
        double getSafetyRating();
        double getValue();
        double getSurvivability();
        double getCollisionScore();

        void sendWarning();
        void calculate();

        Json::Value dump2JSON();

        bool JSON2Object(Json::Value);
};
#endif