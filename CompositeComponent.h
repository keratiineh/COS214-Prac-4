#ifndef COMPOSOITECOMPONENT_H
#define COMPOSOITECOMPONENT_H

#include "Component.h"
#include "TraversalType.h"
using namespace std;

#include <vector>

class CompositeComponent : public Component{
    private:
        std::vector<Component*> children;
    public:
        CompositeComponent(const string& id, const string& name);
        ~CompositeComponent() override;

        void add(Component* component);
        void remove(Component* component);

        const vector<Component*>& getChildren() const;
        string getStatus() const override;

        Iterator* createIterator() override;
        Iterator* createIterator(TraversalType type, string criteria);
    protected:
        vector<Component*> getChildrenForTraversal() const override;



};

#endif
