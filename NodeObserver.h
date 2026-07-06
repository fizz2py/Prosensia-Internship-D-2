#ifndef NODEOBSERVER_H
#define NODEOBSERVER_H

#include <iostream>
#include <memory>

class NodeObserver
{
private:
    std::shared_ptr<int> observedData;

public:
    NodeObserver() = default;

    void observe(const std::shared_ptr<int>& data);

    void printObserved() const;

    bool isObserving() const;
};

#endif