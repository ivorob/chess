#include <stdexcept>
#include "GameObject.h"

GameObject::GameObject()
    : id(),
      visualObject()
{
}

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

GameObject::VisualObject *
GameObject::obtainVisualObject()
{
    if (this->visualObject == nullptr) {
         QPixmap pixmap(":/images/" + getResource() + ".png");
         this->visualObject = new QGraphicsPixmapItem(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
         initVisualObject(this->visualObject);
    }

    return this->visualObject;
}
