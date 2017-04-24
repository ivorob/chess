#ifndef __CHESS_ONLINE_REGISTRY_H__
#define __CHESS_ONLINE_REGISTRY_H__

#include "NetworkManager.h"

class Registry {
public:
    Registry();
    virtual ~Registry();

    NetworkManager *getNetworkManager() const;
private:
    NetworkManager *networkManager;
};

#endif //__CHESS_ONLINE_REGISTRY_H__
