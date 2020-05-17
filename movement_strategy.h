#pragma once

class movementStrategy {

public:
    virtual void set_x(double x) = 0;
    virtual void set_dx(double dx) = 0;
    
    virtual void set_y(double y) = 0;
    virtual void set_dy(double dy) = 0;

    virtual double x() = 0;
    virtual double dx() = 0;

    virtual double y() = 0;
    virtual double dy() = 0;
};

class lockdownMovementStrategy : public movementStrategy{

public:
    lockdownMovementStrategy(int x,int y) : _x(x),_y(y){};

    void set_x(double x);
    void set_dx(double dx);

    void set_y(double y);
    void set_dy(double dy);

    double x(){return _x;};
    double dx(){return _dx;};

    double y(){return _y;};
    double dy(){return _dy;};

private:
    double _x = 0, _y = 0, _dx = 0, _dy = 0;
};

class regularMovementStrategy : public movementStrategy {

public:
    regularMovementStrategy(int x,int y) : _x(x),_y(y){};

    void set_x(double x);
    void set_dx(double dx);

    void set_y(double y);
    void set_dy(double dy);

    double x(){return _x;};
    double dx(){return _dx;};
    
    double y(){return _y;};
    double dy(){return _dy;};

private:
    double _x = 0, _y = 0, _dx = 0, _dy = 0;
};



//Created by Jan Minne Holwerda