#include "Component.h"
#include <string>
using namespace std;

Component::Component(const string& id, const string& name){
    this->id = id;
    this->name = name;

}

string Component::getId() const{
    return id;
}

string Component::getName() const {
    return name;
}