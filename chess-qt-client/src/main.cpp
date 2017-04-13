#include <QtWidgets>
#include <QDebug>
#include "ChessBoard.h"

class MainWindow : public QGraphicsView {
    Q_OBJECT
public:
    MainWindow(QGraphicsScene *scene)
        : QGraphicsView(scene),
          board()
    {
        initScene();
    }

    void resizeEvent(QResizeEvent *event) {
        this->board->setSize(event->size());
        QGraphicsView::setSceneRect(sceneRect());
    }
private:
    void initScene() {
        QPixmap chessboard(":/images/chessboard.png");
        this->board = new ChessBoard(chessboard);
        this->board->setZValue(0);
        scene()->addItem(this->board);

        QGraphicsPixmapItem *item = scene()->addPixmap(QPixmap(":/images/white_king.png").scaled(110, 110, Qt::KeepAspectRatio));
        item->setZValue(1);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);

        item = scene()->addPixmap(QPixmap(":/images/white_queen.png").scaled(110, 110, Qt::KeepAspectRatio));
        item->setZValue(1);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);

        item = scene()->addPixmap(QPixmap(":/images/white_bishop.png").scaled(110, 110, Qt::KeepAspectRatio));
        item->setZValue(1);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);

        item = scene()->addPixmap(QPixmap(":/images/white_knight.png").scaled(110, 110, Qt::KeepAspectRatio));
        item->setZValue(1);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);

        item = scene()->addPixmap(QPixmap(":/images/white_rook.png").scaled(110, 110, Qt::KeepAspectRatio));
        item->setZValue(1);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);

        item = scene()->addPixmap(QPixmap(":/images/white_pawn.png").scaled(110, 110, Qt::KeepAspectRatio));
        item->setZValue(1);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);
    }
private:
    ChessBoard *board;
};

int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    MainWindow mainWindow(&scene);
    mainWindow.setWindowTitle("Chess Online");
    mainWindow.setFixedSize(QSize(800, 800));
    mainWindow.move(QApplication::desktop()->screen()->rect().center() - mainWindow.rect().center());
    mainWindow.show();
    return app.exec();
}

#include "main.moc"
