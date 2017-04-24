#include <QtWidgets>
#include <QTcpSocket>
#include <QDebug>
#include <sstream>
#include "ChessBoard.h"
#include "figures/Pawn.h"
#include "figures/King.h"
#include "figures/Queen.h"
#include "figures/Rook.h"
#include "figures/Knight.h"
#include "figures/Bishop.h"
#include "WhiteDecorator.h"
#include "BlackDecorator.h"

/*class MainWindow : public QGraphicsView {
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
    }
private:
    ChessBoard *board;
    QList<GameObject *> objects;
};*/

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        initUi();
    }

    void initUi() {
        QPushButton *connectButton = new QPushButton("Connect");
        QPushButton *exitButton = new QPushButton("Exit");
        QObject::connect(exitButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
        QObject::connect(connectButton, SIGNAL(clicked()), this, SLOT(connect()));

        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(connectButton);
        mainLayout->addWidget(exitButton);

        setLayout(mainLayout);
        setFixedSize(QSize(150, 100));
    }
private slots:
    void connect() {
        qDebug() << "connect";
        QTcpSocket *tcpSocket = new QTcpSocket(this);

        tcpSocket->connectToHost("localhost", 1111);
        if (tcpSocket->waitForConnected()) {
            std::stringstream stream;
            struct {
                uint32_t size;
                uint8_t command;
                uint32_t version;
            } command = {5, 0, 1};
            stream.write((const char *)&command, sizeof(command));

            const std::string& data = stream.str();
            qDebug() << "data size: " << data.size();
            tcpSocket->write(data.c_str(), data.size());
            qDebug() << tcpSocket->waitForBytesWritten();
        } else {
            qDebug() << tcpSocket->errorString();
        }
    }
};

int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
    /*QGraphicsScene scene;
    MainWindow mainWindow(&scene);
    mainWindow.setWindowTitle("Chess Online");
    mainWindow.setFixedSize(QSize(700, 700));
    mainWindow.move(QApplication::desktop()->screen()->rect().center() - mainWindow.rect().center());
    mainWindow.show();*/
    return app.exec();
}

#include "main.moc"
