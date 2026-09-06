#ifndef SCHEDULESTATE_H
#define SCHEDULESTATE_H

#include "ShotState.h"

class ScheduleState : public ShotState {
public:
    ShotState* checkTransition(Shot* shot) override;
    std::string getName() const override;
};

#endif //SCHEDULESTATE_H