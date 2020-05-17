#pragma once
#include "movement_strategy.h"

//Duration Of Status effect in ticks
constexpr int INCUBATION = 150; //10 ticks = 1 day for sim purposes
constexpr int IMMUNITY = 300;

namespace corsim {

/**
 * A subject is an entity within the simulation. It is modeled as a
 * circle in 2D and can be infected.
 */
    class Subject {
    public:
        Subject(int x, int y, int radius, bool infected, movementStrategy *moveStrategy) :
                moveStrategy(moveStrategy), _x(x), _y(y), _incubation(infected), _radius(radius) {};
        double x();
        double y();
        void set_x(double x);
        void set_y(double y);
        double dx(); //Speed on x axis
        double dy(); //Speed on y axis
        int radius(); //Radius needed for collisions
        void set_dx(double dx);
        void set_dy(double dy);
        bool infected();
        void infect();
        bool immune();
        double angle();
        double speed();
        void tick();
        movementStrategy* moveStrategy = new regularMovementStrategy(0, 0);
        
    private:
        double _x = 0, _y = 0, _dx = 0, _dy = 0;
        int _incubation = INCUBATION;
        int _radius = 0;
        int _immune = 0;
    };
};

//Created by Jan Minne Holwerda