#pragma once
#include "List.h"
class User;

template <typename T, typename Attribute, typename Comparator>
class Sorter
{
    public: 
    bool quickSort(List<T>& list, int left, int right,Comparator comparator);
};

template <typename T, typename Attribute,typename Comparator>
bool Sorter<T, Attribute, Comparator>::quickSort(List<T>& list, int left, int right, Comparator comparator) {
    if (left >= right) return true;

    int i = left;
    int j = right;
    T pivot = list.getElement((left + right) / 2)->getValue();

    while (i <= j) {
        while (comparator(list.getElement(i)->getValue(), pivot) < 0) i++;
        while (comparator(list.getElement(j)->getValue(), pivot) > 0) j--;

        if (i <= j) {
            list.swapElements(i, j);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(list, left, j, comparator);
    if (i < right) quickSort(list, i, right, comparator);

    return true;
}
