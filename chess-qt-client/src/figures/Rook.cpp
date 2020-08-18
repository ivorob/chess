#include "figures/Rook.h"

Chess::Rook::Rook()
{
}

QString
Chess::Rook::getClassId() const
{
    return "R";
}

QString
Chess::Rook::getResource() const
{
    return "rook";
}

void
Chess::Rook::initVisualObject(VisualObject *visualObject)
{
    visualObject->setZValue(1); 
    visualObject->setFlag(QGraphicsItem::ItemIsMovable, true); 
}
