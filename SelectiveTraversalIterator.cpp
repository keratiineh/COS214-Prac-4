#include "SelectiveTraversalIterator.h"

SelectiveTraversalIterator::SelectiveTraversalIterator(Component* root, string& criteria){
     this->position = 0;
    this->criteria = criteria;

    if (root)
    {
        collect(root);
    }
}

void SelectiveTraversalIterator::collect(Component* node){
    if (node->getStatus() == criteria)
    {
        items.push_back(node);

    }
    vector<Component*> kids = node->getChildrenForTraversal();
    for (size_t i = 0; i < kids.size(); i++)
    {
        collect(kids[i]);
    }

    
    
}

bool SelectiveTraversalIterator::hasNext() const{
    return position <items.size();
}

Component* SelectiveTraversalIterator::next(){
    return items[position++];
}
   