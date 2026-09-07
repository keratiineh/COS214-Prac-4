#ifndef INSURANCEDECORATOR_H
#define INSURANCEDECORATOR_H

#include "ComponentDecorator.h"

enum class RiskLevel { LOW, MEDIUM, HIGH};

class InsuranceDecorator : public ComponentDecorator {
    private:
        RiskLevel risk;
        std::string riskLabel() const;
    public:
        InsuranceDecorator(Component* item, RiskLevel r);
        std::string getStatus() const override;
};

#endif