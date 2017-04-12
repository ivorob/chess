#include <QtWidgets>

void
initView(QGraphicsScene *scene)
{
    int size = 64;
    for (int i = 0; i < 8; ++i) {
        int currentColor = ((i % 2) == 0) ? Qt::gray : Qt::white;
        for (int j = 0; j < 8; ++j) {
            QGraphicsRectItem *cell = new QGraphicsRectItem(i * size, j * size, size, size);
            if (currentColor == Qt::gray) {
                cell->setBrush(QBrush(Qt::gray));
                currentColor = Qt::white;
            } else {
                cell->setBrush(QBrush(Qt::white));
                currentColor = Qt::gray;
            }

            scene->addItem(cell);
        }
    }
}

int
main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    QGraphicsView view(&scene);

    initView(&scene);
    view.setWindowTitle("Chess Online");
    view.show();
    return app.exec();
}
