#include <iostream>
#include "CompositeComponent.h"
#include "Iterator.h"
#include "Shot.h"
#include "VFXDecorator.h"
#include "InsuranceDecorator.h"

//has same uniformity as composite pattern
static void printComponent(Component* c) {
    std::cout << "  " << c->getId() << " (" << c->getName() << "): "
              << c->getStatus() << "\n";
}

int main() {
    std::cout << "=========================================\n";
    std::cout << " Scenario A: Morning Production Briefing\n";
    std::cout << "=========================================\n\n";

    CompositeComponent* production = new CompositeComponent("P1", "Heist Sequence");
    CompositeComponent* unitA = new CompositeComponent("UA", "Unit A - Vault Scene");
    CompositeComponent* unitB = new CompositeComponent("UB", "Unit B - Getaway Scene");

    Shot* s1 = new Shot("S1", "Wide establishing shot");
    Shot* s2 = new Shot("S2", "Close-up on lockpick");
    Shot* s3 = new Shot("S3", "Explosion reaction");

    //decorated Shot is built once, then handed to add()
    Component* s2Decorated = new InsuranceDecorator(new VFXDecorator(s2, "Nebula VFX"), RiskLevel::HIGH);

    unitA->add(s1);
    unitA->add(s2Decorated);
    unitB->add(s3);
    production->add(unitA);
    production->add(unitB);

    std::cout << "-- Full traversal (every shot and unit) --\n";
    Iterator* full = production->createIterator();
    while (full->hasNext()) {
        printComponent(full->next());
    }
    delete full;

    std::cout << "\n-- Selective traversal: only Scheduled shots --\n";
    Iterator* scheduled = production->createIterator(TraversalType::SELECTIVE, "Scheduled");
    while (scheduled->hasNext()) {
        printComponent(scheduled->next());
    }
    delete scheduled;

    std::cout << "\n=========================================\n";
    std::cout << " Scenario B: End-of-Day Wrap\n";
    std::cout << "=========================================\n\n";

    std::cout << "-- Attempting to complete S1 before any take is recorded --\n";
    s1->transition(); //Scheduled -> Shooting (always allowed)
    s1->transition(); //guarded: should be rejected, no takes recorded yet
    std::cout << "S1 status after blocked attempt: " << s1->getStatus() << "\n\n";

    std::cout << "-- Recording a take, then retrying --\n";
    s1->recordTake();
    s1->transition(); //now allowed: Shooting -> Completed
    s1->transition(); //Completed -> InPost
    s1->transition(); //InPost -> Approved
    std::cout << "S1 status now: " << s1->getStatus() << "\n\n";

    std::cout << "-- Demonstrating the traversal-modification policy --\n";
    std::cout << "Starting a full traversal over the Production BEFORE any change...\n";
    Iterator* inProgress = production->createIterator();

    std::cout << "Mid-traversal, a new Shot is added to Unit B (structural change):\n";
    Shot* s4 = new Shot("S4", "New pickup shot added late");
    unitB->add(s4);

    std::cout << "\nFinishing the traversal that was already in progress (snapshot - should NOT include S4):\n";
    while (inProgress->hasNext()) {
        printComponent(inProgress->next());
    }
    delete inProgress;

    std::cout << "\nStarting a brand-new traversal AFTER the change (should now include S4):\n";
    Iterator* refreshed = production->createIterator();
    while (refreshed->hasNext()) {
        printComponent(refreshed->next());
    }
    delete refreshed;

    std::cout << "\nOverall production status: " << production->getStatus() << "\n";

    delete production; //recursively deletes unitA, unitB, and every Shot/decorated Shot owned
    return 0;
}