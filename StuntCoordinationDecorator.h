#ifndef STUNTCOORDINATIONDECORATOR_H
#define STUNTCOORDINATIONDECORATOR_H

#include "ComponentDecorator.h"

class StuntCoordinationDecorator : public ComponentDecorator {
    private:
        std::string coordinatorName;
    public:
        StuntCoordinationDecorator(Component* item, std::string coordinator);
        std::string getStatus() const override;
};

#endif