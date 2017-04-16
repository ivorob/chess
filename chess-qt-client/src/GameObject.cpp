#include <stdexcept>
#include "GameObject.h"

GameObject::~GameObject()
{
}

void
GameObject::setId(objectId id)
{
    this->id = id;
}

GameObject::objectId
GameObject::getId() const
{
    return this->id;
}
