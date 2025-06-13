
#include "../Model/QuickSort.h"


void QuickSort::quickSort(char* lista, int left, int right) {
   if(left >= right) {
      return; 
   }

   int mid = (right - left) / 2 + left;
   char pivot = *(lista + mid);
   int i = left;
   int j = right;

   while(i <= j) {
      while(*(lista + i) < pivot) {
         i++;
      }
      while(*(lista + j) > pivot) {
         j--;
      }
      if(i <= j) {
         swap(lista + i, lista + j);
         i++;
         j--;
      }
   }

   if(left < j) {
      quickSort(lista, left, j);
   }
   if (i < right) {
      quickSort(lista, i, right);
   }
   return;
   
}


void QuickSort::swap(char* a, char* b){
   char temp = *a;
   *a = *b;
   *b = temp;
}