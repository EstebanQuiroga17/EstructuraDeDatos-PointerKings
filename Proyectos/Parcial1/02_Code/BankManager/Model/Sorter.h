#pragma once
#include "List.h"
class User;

template <typename T, typename Attribute, typename Comparator>
class Sorter
{
    public: 
    bool quickSort(List<T>& list, int left, int right,Comparator comparator);
    void quickSortByAttribute(List<T>& list, int left, int right, Attribute T::* attribute);
};

template <typename T, typename Attribute,typename Comparator>
bool Sorter<T, Attribute, Comparator>::quickSort(List<T>& list, int left, int right,Comparator comparator) {
    if (left >= right) {
        return true; 
    }
    int i = left, j = right;
    Node<T>* pivot = list.getElement((left + right) / 2);

    while(comparator(pivot->getValue(), list.getElement(i)->getValue()) > 0) {
        i++;
    }


    return true;
}

template <typename T, typename Attribute, typename Comparator>
void Sorter<T, Attribute, Comparator>::quickSortByAttribute(List<T>& list, int left, int right, Attribute T::* attr) {
    // TODO: implementación
}