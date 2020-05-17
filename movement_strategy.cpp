#include "movement_strategy.h"

void regularMovementStrategy::set_x(double x){this->_x = x;};
void regularMovementStrategy::set_dx(double x){this->_dx = x;};

void regularMovementStrategy::set_y(double y){this->_y = y;};
void regularMovementStrategy::set_dy(double y){this->_dy = y;};


void lockdownMovementStrategy::set_x(double x){};
void lockdownMovementStrategy::set_dx(double x){};

void lockdownMovementStrategy::set_y(double y){};
void lockdownMovementStrategy::set_dy(double y){};

//Created by Jan Minne Holwerda