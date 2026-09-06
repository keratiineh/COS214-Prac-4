#include "ScheduleState.h"
#include "ShootingState.h"

ShotState* ScheduleState::checkTransition(Shot* shot) {
    (void)shot;
    return new ShootingState();
}

std::string ScheduleState::getName() const {
    return "Scheduled";
}