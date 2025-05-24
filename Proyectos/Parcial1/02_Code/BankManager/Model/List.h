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
    void guardarBinario(std::ofstream& out) const;
    bool cargarBinario(std::ifstream& in);


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

// Guarda la lista completa en binario (recorriendo solo con punteros, sin corchetes)
template <typename T>
void List<T>::guardarBinario(std::ofstream& out) const {
    // Contar elementos
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
        actual->getValue().guardarBinario(out); // Asume que T tiene guardarBinario
        actual = actual->getNextNode();
    }
}

template <typename T>
bool List<T>::cargarBinario(std::ifstream& in) {
    // Limpiar la lista primero (opcional pero recomendado)
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
        obj.cargarBinario(in); // Asume que T tiene cargarBinario
        insert(obj);           // Inserta usando solo punteros
    }
    return true;
}
