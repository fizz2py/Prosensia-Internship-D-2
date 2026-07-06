#include <iostream>
#include <memory>
#include "LinkedList.h"
#include "NodeObserver.h"

int main()
{
    LinkedList list;

    // Append nodes
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    std::cout << "Original List: ";
    list.print();

    // Create an observer
    NodeObserver observer;

    // Observe the node containing 30
    std::shared_ptr<int> observedNode = list.getSharedData(30);

    if (observedNode)
    {
        observer.observe(observedNode);

        std::cout << "Observer Output: ";
        observer.printObserved();
    }

    // Remove a node
    list.remove(20);

    std::cout << "\nList after removing 20: ";
    list.print();

    // Remove another node
    list.remove(50);

    std::cout << "List after removing 50: ";
    list.print();

    // Try observing a node that doesn't exist
    auto missingNode = list.getSharedData(100);

    if (!missingNode)
    {
        std::cout << "\nNode with value 100 not found." << std::endl;
    }

    std::cout << "\nProgram completed successfully." << std::endl;

    return 0;
}