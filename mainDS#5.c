#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  This code demonstrates the usage of different sorting algorithms and compares the performance of these algorithms by calculating their
// time complexities and the number of array accesses during sorting operations.

static int ctQckSort, ctBblSort, ctInsSort;
static int arr1[100], arr2[100], arr3[100];

void swap(int d[], int a, int b){
    int temp = d[a];
    d[a] = d[b];
    d[b] = temp;
}

void insertionSort(int d[], int n){
    for (int i = 1; i < n; i++){
        for (int j = i; j > 0; j--){
            if (d[j - 1] > d[j]){
                swap(d, j, j - 1);
                ctInsSort++;
            }
            else
                break;
        }
    }
}

void quicksort(int number[], int first, int last){
   int i, j, pivot, temp;
   if (first < last){
      pivot = first;
      i = first;
      j = last;
      while (i < j){
         while (number[i] <= number[pivot] && i < last)
            i++;
         while (number[j] > number[pivot])
            j--;
         if (i < j){
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
            ctQckSort++;
         }
      }
      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;
      quicksort(number, first, j - 1);
      quicksort(number, j + 1, last);
   }
}

void bubbleSort(int d[], int n){
    for (int i = n; i > 1; i--){
        for (int j = 0; j < i - 1; j++){
            if (d[j + 1] < d[j]){
                swap(d, j, j + 1);
                ctBblSort++;
            }
        }
    }
}

void generateRandomNumbers(int d[]){
    for (int i = 0; i < 100; i++){
        d[i] = (rand() % 900) + 100;
    }
}

void setArrays(){
    generateRandomNumbers(arr1);
    generateRandomNumbers(arr2);
    generateRandomNumbers(arr3);
}

void printArray(int d[], int n){
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d-", d[i]);
    }
    printf("\n\n");
}

void beforeSorting(){
    printf("\n--------Array1 before sorting--------\n");
    printArray(arr1, 100);
    printf("\n--------Array2 before sorting--------\n");
    printArray(arr2, 100);
    printf("\n--------Array3 before sorting--------\n");
    printArray(arr3, 100);
}

void afterSorting(){
    insertionSort(arr1, 100);
    bubbleSort(arr2, 100);
    quicksort(arr3, 0, 100);
    printf("\n--------Array1 after sorting--------\n");
    printf("Using Insertion Sort!\n");
    printf("Time Complexity = O(n^2) --> Worst Case\n");
    printf("This sort required %d array accesses.\n", ctInsSort);
    printArray(arr1, 100);
    printf("\n--------Array2 after sorting--------\n");
    printf("Using Bubble Sort!\n");
    printf("Time Complexity = O(n^2) --> Worst Case\n");
    printf("This sort required %d array accesses.\n", ctBblSort);
    printArray(arr2, 100);
    printf("\n--------Array3 after sorting--------\n");
    printf("Using Quick Sort!\n");
    printf("Time Complexity = n log(n) --> Average Case\n");
    printf("This sort required %d array accesses.\n", ctQckSort);
    printArray(arr3, 100);
}

void start(){
    setArrays();
    beforeSorting();
    printf("\n************************************************\n\n");
    afterSorting();
}

int main(){
    start();
    return 0;
}
