#ifndef __CHESS_ONLINE_NETWORK_MANAGER_H__
#define __CHESS_ONLINE_NETWORK_MANAGER_H__

class NetworkManager {
public:
    NetworkManager();
    ~NetworkManager();

    bool addToQueue(const std::string& data);
    std::string readFromQueue();
};

#endif //__CHESS_ONLINE_NETWORK_MANAGER_H__
