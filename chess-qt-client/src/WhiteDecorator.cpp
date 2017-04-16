#include "WhiteDecorator.h"

WhiteDecorator::WhiteDecorator(GameObject *object)
    : object(object)
{
}

WhiteDecorator::~WhiteDecorator()
{
    delete object;
}

QString
WhiteDecorator::getClassId() const
{
    return "W" + this->object->getClassId();
}

QString
WhiteDecorator::getResource() const
{
    return "white_" + this->object->getResource();
}

void
WhiteDecorator::initVisualObject(VisualObject *visualObject)
{
    this->object->initVisualObject(visualObject);
}
