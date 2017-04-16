#include "figures/Pawn.h"

Chess::Pawn::Pawn()
{
}

QString
Chess::Pawn::getClassId() const
{
    return "P";
}

QString
Chess::Pawn::getResource() const
{
    return "pawn";
}

void
Chess::Pawn::initVisualObject(VisualObject *visualObject)
{
    visualObject->setZValue(1); 
    visualObject->setFlag(QGraphicsItem::ItemIsMovable, true); 
}
