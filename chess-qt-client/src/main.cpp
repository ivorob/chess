#include <QtWidgets>
#include <QDebug>
#include "ChessBoard.h"
#include "figures/Pawn.h"
#include "figures/King.h"
#include "figures/Queen.h"
#include "figures/Rook.h"
#include "figures/Knight.h"
#include "figures/Bishop.h"
#include "WhiteDecorator.h"
#include "BlackDecorator.h"

class MainWindow : public QGraphicsView {
    Q_OBJECT
public:
    MainWindow(QGraphicsScene *scene)
        : QGraphicsView(scene),
          board()
    {
        initScene();
    }

    ~MainWindow() {
        for (GameObject *object : this->objects) {
            delete object;
        }
    }

    void resizeEvent(QResizeEvent *event) {
        this->board->setSize(event->size());
        QGraphicsView::setSceneRect(sceneRect());
    }
private:
    void moveTo(QGraphicsItem *item, int x, int y) {
        item->setX(22 + x * 79);
        item->setY(700 - y * 79 - 125);
    }

    QGraphicsItem *addGameObject(GameObject *object) {
        this->objects.push_back(object);
        QGraphicsItem *item = object->obtainVisualObject();
        scene()->addItem(item);
        return item;
    }

    void initScene() {
        QPixmap chessboard(":/images/chessboard.png");
        this->board = new ChessBoard(chessboard);
        this->board->setZValue(0);
        scene()->addItem(this->board);

        moveTo(addGameObject(new WhiteDecorator(new Chess::King)), 4, 0);
        moveTo(addGameObject(new BlackDecorator(new Chess::King)), 4, 7);

        moveTo(addGameObject(new WhiteDecorator(new Chess::Queen)), 3, 0);
        moveTo(addGameObject(new BlackDecorator(new Chess::Queen)), 3, 7);

        moveTo(addGameObject(new WhiteDecorator(new Chess::Rook)), 0, 0);
        moveTo(addGameObject(new WhiteDecorator(new Chess::Rook)), 7, 0);

        moveTo(addGameObject(new BlackDecorator(new Chess::Rook)), 0, 7);
        moveTo(addGameObject(new BlackDecorator(new Chess::Rook)), 7, 7);

        moveTo(addGameObject(new WhiteDecorator(new Chess::Knight)), 1, 0);
        moveTo(addGameObject(new WhiteDecorator(new Chess::Knight)), 6, 0);

        moveTo(addGameObject(new BlackDecorator(new Chess::Knight)), 1, 7);
        moveTo(addGameObject(new BlackDecorator(new Chess::Knight)), 6, 7);

        moveTo(addGameObject(new WhiteDecorator(new Chess::Bishop)), 2, 0);
        moveTo(addGameObject(new WhiteDecorator(new Chess::Bishop)), 5, 0);

        moveTo(addGameObject(new BlackDecorator(new Chess::Bishop)), 2, 7);
        moveTo(addGameObject(new BlackDecorator(new Chess::Bishop)), 5, 7);

        for (int i = 0; i < 8; ++i) {
            moveTo(addGameObject(new WhiteDecorator(new Chess::Pawn)), i, 1);
        }

        for (int i = 0; i < 8; ++i) {
            moveTo(addGameObject(new BlackDecorator(new Chess::Pawn)), i, 6);
        }


        /*QGraphicsPixmapItem *item = scene()->addPixmap(QPixmap(":/images/white_king.png").scaled(100, 100, Qt::KeepAspectRatio));
        item->setZValue(1);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);

        item = scene()->addPixmap(QPixmap(":/images/white_queen.png").scaled(100, 100, Qt::KeepAspectRatio));
        item->setZValue(1);
        item->setFlag(QGraphicsItem::ItemIsMovable, true);

        for (int i = 0; i < 2; ++i) {
            item = scene()->addPixmap(QPixmap(":/images/white_bishop.png").scaled(100, 100, Qt::KeepAspectRatio));
            item->setZValue(1);
            item->setFlag(QGraphicsItem::ItemIsMovable, true);

            item = scene()->addPixmap(QPixmap(":/images/white_knight.png").scaled(100, 100, Qt::KeepAspectRatio));
            item->setZValue(1);
            item->setFlag(QGraphicsItem::ItemIsMovable, true);

            item = scene()->addPixmap(QPixmap(":/images/white_rook.png").scaled(100, 100, Qt::KeepAspectRatio));
            item->setZValue(1);
            item->setFlag(QGraphicsItem::ItemIsMovable, true);
        }

        for (int i = 0; i < 8; ++i) {
            item = scene()->addPixmap(QPixmap(":/images/white_pawn.png").scaled(100, 100, Qt::KeepAspectRatio));
            item->setZValue(1);
            item->setFlag(QGraphicsItem::ItemIsMovable, true);
        }*/
    }
private:
    ChessBoard *board;
    QList<GameObject *> objects;
};

int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    MainWindow mainWindow(&scene);
    mainWindow.setWindowTitle("Chess Online");
    mainWindow.setFixedSize(QSize(700, 700));
    mainWindow.move(QApplication::desktop()->screen()->rect().center() - mainWindow.rect().center());
    mainWindow.show();
    return app.exec();
}

#include "main.moc"
