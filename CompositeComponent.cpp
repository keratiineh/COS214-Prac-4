#include "CompositeComponent.h"
#include "FullTraversalIterator.h"
#include "SelectiveTraversalIterator.h"

CompositeComponent::CompositeComponent(const string& id, const string& name) : Component(id, name){
    
}

CompositeComponent::~CompositeComponent(){
    for(Component* child : children){
        delete child;
    }
}

void CompositeComponent::add(Component* component){
    children.push_back(component);
}

void CompositeComponent::remove(Component* component){
    for (auto i = children.begin(); i != children.end(); i++)
    {
        if (*i == component)
        {
            delete *i;
            children.erase(i);
            return;
        }
        
    }
    
}

const vector<Component*>& CompositeComponent::getChildren() const{
    return children;
}

string CompositeComponent::getStatus() const {
    int total = static_cast<int>(children.size());
    int approved = 0;
    for (Component* child : children)
    {
        if(child->getStatus()=="Approved"){
            ++approved;
        }
    }

    return to_string(approved) + "/" + to_string(total) + " approved";
    
}

Iterator* CompositeComponent::createIterator(){
    return createIterator(TraversalType::FULL, "");

}

Iterator* CompositeComponent::createIterator(TraversalType type, string criteria) {
    switch (type)
    {
    case TraversalType::SELECTIVE:
        return new SelectiveTraversalIterator(this, criteria);
        break;
    case TraversalType::FULL:
    default:
        return new FullTraversalIterator(this);
    }
    
}

vector<Component*> CompositeComponent::getChildrenForTraversal() const {
    return children;
}