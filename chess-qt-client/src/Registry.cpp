#include "Registry.h"

Registry::Registry()
    : networkManager()
{
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

void
Registry::setNetworkManager(NetworkManager *networkManager)
{
    this->networkManager = networkManager;
}
