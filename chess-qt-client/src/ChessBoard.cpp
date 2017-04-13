#include <QPainter>
#include "ChessBoard.h"

ChessBoard::ChessBoard(const QPixmap& pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem(pixmap, parent),
      size(QSizeF(400, 400))
{
}

void
ChessBoard::setSize(const QSizeF& size)
{
    this->size = size;
}

QRectF
ChessBoard::boundingRect() const
{
    return QRectF(QPointF(0, 0), this->size);
}

void
ChessBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().toRect(), pixmap());
}
