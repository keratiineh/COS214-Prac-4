#ifndef SHOOTINGSTATE_H
#define SHOOTINGSTATE_H

#include "ShotState.h"

class ShootingState : public ShotState {
public:
    ShotState* checkTransition(Shot* shot) override;
    std::string getName() const override;
};

#endif //SHOOTINGSTATE_H