#include "figures/Knight.h"

Chess::Knight::Knight()
{
}

QString
Chess::Knight::getClassId() const
{
    return "N";
}

QString
Chess::Knight::getResource() const
{
    return "knight";
}

void
Chess::Knight::initVisualObject(VisualObject *visualObject)
{
    visualObject->setZValue(1); 
    visualObject->setFlag(QGraphicsItem::ItemIsMovable, true); 
}
