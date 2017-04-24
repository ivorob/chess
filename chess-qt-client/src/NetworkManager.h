#ifndef __CHESS_ONLINE_NETWORK_MANAGER_H__
#define __CHESS_ONLINE_NETWORK_MANAGER_H__

#include <string>
#include <QThread>
#include <QTcpSocket>

class NetworkManager : public QObject {
    Q_OBJECT
public:
    NetworkManager(QTcpSocket *tcpSocket, QObject *parent = nullptr);
    ~NetworkManager();

    bool addToQueue(const std::string& data);
    std::string readFromQueue();
signals:
    void newPacket(const std::string& data);
private slots:
    void process();
private:
    QThread *thread;
    QTcpSocket *tcpSocket;
};

#endif //__CHESS_ONLINE_NETWORK_MANAGER_H__
