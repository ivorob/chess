#include "figures/Bishop.h"

Chess::Bishop::Bishop()
{
}

QString
Chess::Bishop::getClassId() const
{
    return "B";
}

QString
Chess::Bishop::getResource() const
{
    return "bishop";
}

void
Chess::Bishop::initVisualObject(VisualObject *visualObject)
{
    visualObject->setZValue(1); 
    visualObject->setFlag(QGraphicsItem::ItemIsMovable, true); 
}
