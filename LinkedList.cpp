#include "LinkedList.h"

// Node constructor
LinkedList::Node::Node(int value)
    : data(value),
      sharedData(std::make_shared<int>(value)),
      next(nullptr)
{
}

// Add a node to the end of the list
void LinkedList::append(int value)
{
    auto newNode = std::make_unique<Node>(value);

    if (!head)
    {
        head = std::move(newNode);
        return;
    }

    Node* current = head.get();

    while (current->next)
    {
        current = current->next.get();
    }

    current->next = std::move(newNode);
}

// Print all nodes
void LinkedList::print() const
{
    Node* current = head.get();

    while (current)
    {
        std::cout << current->data << " ";
        current = current->next.get();
    }

    std::cout << std::endl;
}

// Remove a node by value
void LinkedList::remove(int value)
{
    if (!head)
        return;

    // Remove head node
    if (head->data == value)
    {
        head = std::move(head->next);
        return;
    }

    Node* current = head.get();

    while (current->next && current->next->data != value)
    {
        current = current->next.get();
    }

    if (current->next)
    {
        current->next = std::move(current->next->next);
    }
}

// Return a shared_ptr to the node's data
std::shared_ptr<int> LinkedList::getSharedData(int value) const
{
    Node* current = head.get();

    while (current)
    {
        if (current->data == value)
        {
            return current->sharedData;
        }

        current = current->next.get();
    }

    return nullptr;
}