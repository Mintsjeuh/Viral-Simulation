#include "simulation.h"
#include <iostream>
#include <random>
#include <math.h>
#include "html_canvas.h"
#include "ChartJS_handler.h"

//Constants to control the simulation
const int SUBJECT_COUNT = 200;
const int SIM_WIDTH = 800;
const int SIM_HEIGHT = 500;
const int SUBJECT_RADIUS = 2;

int main() {
    corsim::Simulation s(SIM_WIDTH, SIM_HEIGHT, std::make_unique<corsim::HTMLCanvas>(30, 150, SIM_WIDTH, SIM_HEIGHT),
                         std::make_unique<corsim::ChartJSHandler>());

    //Code to randomly generate certain numbers, which is done by using certain distributions
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist_w(1.0, SIM_WIDTH);
    std::uniform_real_distribution<double> dist_h(1.0, SIM_HEIGHT);
    std::uniform_real_distribution<double> dist_dx(-1.0, 1.0);
    std::uniform_real_distribution<double> dist_dy(-1.0, 1.0);

    for (int i = 0; i < SUBJECT_COUNT; ++i) {
        double x = dist_w(mt); //Randomly generate x position
        double y = dist_h(mt); //Randomly generate y position

        //Set all the subject to the lockdownMoventStrategy
        corsim::Subject su(x, y, SUBJECT_RADIUS, false, new lockdownMovementStrategy(x, y));

        //Set 1 in 4 subjects to the regularMovementStrategy
        if (i % 3 == 0) { su.moveStrategy = new regularMovementStrategy(x, y); }

        su.set_dx(dist_dx(mt));
        su.set_dy(dist_dy(mt));

        //Set the infected to the last subject with the regularMovementStrategy Index 198
        if (i == SUBJECT_COUNT - 2) {
            su.infect();
        }

        s.add_subject(std::move(su));
    }

    s.run();
}

//Created by Jan Minne Holwerda