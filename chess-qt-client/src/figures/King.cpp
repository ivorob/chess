#include "figures/King.h"

Chess::King::King()
{
}

QString
Chess::King::getClassId() const
{
    return "K";
}

QString
Chess::King::getResource() const
{
    return "king";
}

void
Chess::King::initVisualObject(VisualObject *visualObject)
{
    visualObject->setZValue(1); 
    visualObject->setFlag(QGraphicsItem::ItemIsMovable, true); 
}
