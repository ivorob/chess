#include "Registry.h"

Registry::Registry()
    : networkManager()
{
    this->networkManager = new NetworkManager;
}

Registry::~Registry()
{
    delete this->networkManager;
}

NetworkManager *
Registry::getNetworkManager() const
{
    return this->networkManager;
}
