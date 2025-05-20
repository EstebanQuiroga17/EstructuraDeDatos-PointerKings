#pragma once
#include "Node.h"
#include <iostream>

template <typename T>
class List {
private:
    Node<T>* head;

public:
    List();
    ~List();

    void insert(T value);
    bool deleteByValue(T value);
    Node<T>* search(T value);
    bool update(Node<T>* oldValue, Node<T>* newValue);
    void printList();

    Node<T>* getHead() const;
    void setHead(Node<T>* newHead);
};


//Implementation

template <typename T>
List<T>::List() : head(nullptr) {}

template <typename T>
List<T>::~List() {
    if (!head) return;
    Node<T>* current = head->getNextNode();
    while (current != head) {
        Node<T>* next = current->getNextNode();
        delete current;
        current = next;
    }
    delete head;
    head = nullptr;
}

//Iserts a new node at the end of the list
template <typename T>
void List<T>::insert(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
        head->setNextNode(head);
        head->setPreviousNode(head);
    } else {
        Node<T>* tail = head->getPreviousNode();
        tail->setNextNode(newNode);
        newNode->setPreviousNode(tail);
        newNode->setNextNode(head);
        head->setPreviousNode(newNode);
    }
}

template <typename T>
bool List<T>::deleteByValue(T value) {
    if (!head) return false;
    Node<T>* current = head;
    do {
        if (current->getValue() == value) {
            if (current->getNextNode() == current) {
                delete current;
                head = nullptr;
                return true;
            }
            Node<T>* previous = current->getPreviousNode();
            Node<T>* next = current->getNextNode();
            previous->setNextNode(next);
            next->setPreviousNode(previous);
            if (current == head)
                head = next;
            delete current;
            return true;
        }
        current = current->getNextNode();
    } while (current != head);
    return false;
}

template <typename T>
Node<T>* List<T>::search(T value) {
    if (!head){ 
        return nullptr;
    }
    Node<T>* current = head;
    do {
        if (current->getValue() == value){
            return current;
        }
        current = current->getNextNode();
    } while (current != head);
    return nullptr;
}

template <typename T>
bool List<T>::update(Node<T>* oldValue, Node<T>* newValue) {
    if (!oldValue || !newValue){
         return false;
    }
    oldValue->setValue(newValue->getValue());
    return true;
}

template <typename T>
void List<T>::printList() {
    if (!head) {
        std::cout << "Lista vacía" << std::endl;
        return;
    }
    Node<T>* current = head;
    do {
        std::cout << current->getValue() << " ";
        current = current->getNextNode();
    } while (current != head);
    std::cout << std::endl;
}

template <typename T>
Node<T>* List<T>::getHead() const {
    return head;
}

template <typename T>
void List<T>::setHead(Node<T>* newHead) {
    head = newHead;
}