#include "ShootingState.h"
#include "CompletedState.h"
#include <iostream>

ShotState* ShootingState::checkTransition(Shot* shot) {
    if (shot->getTakesRecorded() < 1) {
        std::cout << "Cannot complete: no takes recorded yet.\n";
        return nullptr;
    }
    return new CompletedState();
}

std::string ShootingState::getName() const {
    return "Shooting";
}