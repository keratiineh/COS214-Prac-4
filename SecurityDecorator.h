#ifndef SECURITYDECORATOR_H
#define SECURITYDECORATOR_H

#include "ComponentDecorator.h"

class SecurityDecorator : public ComponentDecorator {
    private:
        std::string clearanceLevel;
    public:
        SecurityDecorator(Component* item, std::string clearance);
        std::string getStatus() const override;
};

#endif