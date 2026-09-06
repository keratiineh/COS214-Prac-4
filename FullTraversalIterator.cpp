#include "FullTraversalIterator.h"

using namespace std;

FullTraversalIterator::FullTraversalIterator(Component* root){
    this->position = 0;
    if (root)
    {
        collect(root);
    }
    
}

void FullTraversalIterator::collect(Component* node){
    items.push_back(node);
    vector<Component*> kids = node->getChildrenForTraversal();

    for (size_t i = 0; i < kids.size(); i++)
    {
        collect(kids[i]);
    }
    
}

bool FullTraversalIterator::hasNext() const {
    return position < items.size();
}

Component* FullTraversalIterator::next(){
    return items[position++];
}