#include "subject.h"
#include <math.h>

namespace corsim {

    double Subject::x() {
        return this->moveStrategy->x();
    }

    double Subject::y() {
        return this->moveStrategy->y();
    }

    void Subject::set_x(double x) {
        this->moveStrategy->set_x(x);
    }

    void Subject::set_y(double y) {
        this->moveStrategy->set_y(y);
    }

    double Subject::dx() {
        return this->moveStrategy->dx();
    }

    double Subject::dy() {
        return this->moveStrategy->dy();
    }

    void Subject::set_dx(double dx) {
        this->moveStrategy->set_dx(dx);
    }

    void Subject::set_dy(double dy) {
        this->moveStrategy->set_dy(dy);
    }

    int Subject::radius() {
        return this->_radius;
    }

    bool Subject::infected() {
        return this->_incubation > 0;
    }

    void Subject::infect() {
        if(!_immune)
            this->_incubation = INCUBATION;
    }

    bool Subject::immune() {
        return this->_immune > 0;
    }

    double Subject::angle() {
        return atan2(dy(), dx());
    }

    double Subject::speed() {
        return sqrt(dx() * dx() + dy() * dy());
    }

    void Subject::tick(){
        if(_incubation > 1){
            --_incubation;
        }
        else if(_immune > 0) {
            --_immune;
        }
        else if(_incubation == 1){
            --_incubation;
            _immune = IMMUNITY;
        }
    }
}