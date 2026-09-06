#include "ShootingState.h"
#include "CompletedState.h"

ShotState* ShootingState::checkTransition(Shot* shot) {
    (void)shot;
    return new CompletedState();
}

std::string ShootingState::getName() const {
    return "Shooting";
}