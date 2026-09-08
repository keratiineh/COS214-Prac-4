#include "InsuranceDecorator.h"

InsuranceDecorator::InsuranceDecorator(Component* item, RiskLevel r) 
    : ComponentDecorator(item), risk(r) {}

std::string InsuranceDecorator::riskLabel() const {
    switch (risk) {
        case RiskLevel::LOW:
            return "low risk";
        case RiskLevel::MEDIUM:
            return "medium risk";
        case RiskLevel::HIGH:
            return "high risk";
    }
    return "unknown risk";
}

std::string InsuranceDecorator::getStatus() const {
    return wrapped->getStatus() + " | insured (" + riskLabel() + ")";
}