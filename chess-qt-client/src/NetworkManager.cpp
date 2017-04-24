#include <QDebug>
#include "NetworkManager.h"

NetworkManager::NetworkManager(QTcpSocket *tcpSocket, QObject *parent)
    : QObject(parent),
      thread(),
      tcpSocket(tcpSocket)
{
    this->thread = new QThread(parent);
    moveToThread(this->thread);
    this->thread->start();

    QObject::connect(this->thread, SIGNAL(started()), this, SLOT(process()));
}

NetworkManager::~NetworkManager()
{
    delete this->tcpSocket;
}

bool
NetworkManager::addToQueue(const std::string& data)
{
}

std::string
NetworkManager::readFromQueue()
{
    return std::string();
}

void
NetworkManager::process()
{
    qDebug() << "process NetworkManager queue";
    emit newPacket("Hello");
}
