#ifndef SHOT_H
#define SHOT_H

#include "Component.h"
#include "ShotState.h"

/*
    Shot(Composite pattern - Leaf; State pattern - Context)

    A Shot owns its current lifecycle state via composition: it creates
    and destroys ShotState objects itself, and nothing else shares them.
    transition() delegates the "what's next" decision to the current
    state via checkTransition(), then performs the actual swap here so
    that allocation/deletion of states lives in exactly one place
 */
class Shot : public Component {
private:
    ShotState* currentState;

public:
    Shot(const std::string& id, const std::string& name);

    /*Advances the lifecycle by one step if a valid transition exists
    from the current state. Does nothing (state prints its own
    message) if the transition is invalid.*/
    void transition();

    //Directly installs a new state, deleting the previous one
    void setState(ShotState* state);

    std::string getStatus() const override;

    Iterator* createIterator() const override; //due to shot also being a Leaf (but it has no children to iterate over)
    ~Shot() override;
};

#endif //SHOT_H