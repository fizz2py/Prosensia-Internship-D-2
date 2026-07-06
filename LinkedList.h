#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <memory>

class LinkedList
{
private:
    // Nested Node structure
    struct Node
    {
        int data;
        std::shared_ptr<int> sharedData;
        std::unique_ptr<Node> next;

        explicit Node(int value);
    };

    std::unique_ptr<Node> head;

public:
    LinkedList() = default;
    ~LinkedList() = default;

    // Disable copying because unique_ptr cannot be copied
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Allow moving
    LinkedList(LinkedList&&) = default;
    LinkedList& operator=(LinkedList&&) = default;

    void append(int value);
    void print() const;
    void remove(int value);

    std::shared_ptr<int> getSharedData(int value) const;
};

#endif