#include "NodeObserver.h"

void NodeObserver::observe(const std::shared_ptr<int>& data)
{
    observedData = data;
}

void NodeObserver::printObserved() const
{
    if (observedData)
    {
        std::cout << "Observed value: " << *observedData << std::endl;
    }
    else
    {
        std::cout << "No node is being observed." << std::endl;
    }
}

bool NodeObserver::isObserving() const
{
    return observedData != nullptr;
}