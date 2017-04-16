#include "BlackDecorator.h"

BlackDecorator::BlackDecorator(GameObject *object)
    : object(object)
{
}

BlackDecorator::~BlackDecorator()
{
    delete object;
}

QString
BlackDecorator::getClassId() const
{
    return "B" + this->object->getClassId();
}

QString
BlackDecorator::getResource() const
{
    return "black_" + this->object->getResource();
}

void
BlackDecorator::initVisualObject(VisualObject *visualObject)
{
    this->object->initVisualObject(visualObject);
}
