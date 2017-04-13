#ifndef __CHESS_ONLINE_CHESS_BOARD_H__
#define __CHESS_ONLINE_CHESS_BOARD_H__

#include <QGraphicsPixmapItem>

class ChessBoard : public QGraphicsPixmapItem {
public:
    ChessBoard(const QPixmap& pixmap, QGraphicsItem *parent = 0);

    void setSize(const QSizeF& size);
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    QSizeF size;
};

#endif //__CHESS_ONLINE_CHESS_BOARD_H__
