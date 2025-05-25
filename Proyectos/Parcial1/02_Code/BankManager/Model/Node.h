#pragma once

template <typename T>
class Node {
private:
    T value;
    Node<T>* nextNode;
    Node<T>* previousNode;

public:
    Node(const T& val, Node<T>* next = nullptr, Node<T>* prev = nullptr);
    ~Node();

    T& getValue();
    const T& getValue() const;

    void setValue(const T& val);

    Node<T>* getNextNode() const;
    void setNextNode(Node<T>* next);

    Node<T>* getPreviousNode() const;
    void setPreviousNode(Node<T>* prev);
};


template <typename T>
Node<T>::Node(const T& val, Node<T>* next, Node<T>* prev)
    : value(val), nextNode(next), previousNode(prev) {}

template <typename T>
Node<T>::~Node()
{
}

template <typename T>
const T& Node<T>::getValue() const
{
    return value;
}

template <typename T>
void Node<T>::setValue(const T& newValue)
{
    value = newValue;
}

template <typename T>
Node<T>* Node<T>::getNextNode() const
{
    return nextNode;
}

template <typename T>
void Node<T>::setNextNode(Node<T>* newNextNode)
{
    nextNode = newNextNode;
}

template <typename T>
Node<T>* Node<T>::getPreviousNode() const
{
    return previousNode;
}

template <typename T>
void Node<T>::setPreviousNode(Node<T>* newPreviousNode)
{
    previousNode = newPreviousNode;
}

template <typename T>
T& Node<T>::getValue() {
    return value;
}
