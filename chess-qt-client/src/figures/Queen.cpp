#include "figures/Queen.h"

Chess::Queen::Queen()
{
}

QString
Chess::Queen::getClassId() const
{
    return "Q";
}

QString
Chess::Queen::getResource() const
{
    return "queen";
}

void
Chess::Queen::initVisualObject(VisualObject *visualObject)
{
    visualObject->setZValue(1); 
    visualObject->setFlag(QGraphicsItem::ItemIsMovable, true); 
}
