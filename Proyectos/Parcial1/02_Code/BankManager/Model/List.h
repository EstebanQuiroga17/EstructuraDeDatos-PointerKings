#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>

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
    void saveBinary(std::ofstream& out) const;
    bool loadBinary(std::ifstream& in);
    int getSize();
    Node<T>* getElement(int index);
    Node<T>* getHead() const;
    void setHead(Node<T>* newHead);
    void swapElements(int index1, int index2);
};




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
        std::cout << "Lista vacia" << std::endl;
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


template <typename T>
void List<T>::saveBinary(std::ofstream& out) const {
   
    int cantidad = 0;
    Node<T>* actual = head;
    if (actual) {
        do {
            cantidad++;
            actual = actual->getNextNode();
        } while (actual != head);
    }
    out.write(reinterpret_cast<const char*>(&cantidad), sizeof(int));

    actual = head;
    for (int i = 0; i < cantidad; ++i) {
        actual->getValue().saveBinary(out); 
        actual = actual->getNextNode();
    }
}

template <typename T>
bool List<T>::loadBinary(std::ifstream& in) {
    
    if (head) {
        Node<T>* current = head->getNextNode();
        while (current != head) {
            Node<T>* next = current->getNextNode();
            delete current;
            current = next;
        }
        delete head;
        head = nullptr;
    }

    int cantidad = 0;
    in.read(reinterpret_cast<char*>(&cantidad), sizeof(int));

    for (int i = 0; i < cantidad; ++i) {
        T obj;
        obj.loadBinary(in);
        insert(obj);           
    }
    return true;
}

template <typename T>
int List<T>::getSize() {
    if (!head) return 0;
    int size = 0;
    Node<T>* current = head;
    do {
        size++;
        current = current->getNextNode();
    } while (current != head);
    return size;
}

template <typename T>
Node<T>* List<T>::getElement(int index){
    Node<T>* current = head;
    if(!head || index < 0 || index >= getSize()) {
        return nullptr; 
    }
    for (int i = 0; i < index; ++i) {
        current = current->getNextNode();
        if (current == head) {
            return nullptr; 
        }
    }
    return current;
}

template <typename T>
void swap(int index1, int index2){
    if (index1 < 0 || index2 < 0 || index1 == index2) {
        return; 
    }
    Node<T>* node1 = getElement(index1);
    Node<T>* node2 = getElement(index2);
    if (!node1 || !node2) {
        return; 
    }
    T temp = node1->getValue();
    node1->setValue(node2->getValue());
    node2->setValue(temp);
}