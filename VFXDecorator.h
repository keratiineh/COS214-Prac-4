#ifndef VFXDECORATOR_H
#define VFXDECORATOR_H  

#include "ComponentDecorator.h"

class VFXDecorator : public ComponentDecorator {
    private:
        std::string vfxHouse;
    public:
        VFXDecorator(Component* item, std::string house);
        std::string getStatus() const override;
};

#endif