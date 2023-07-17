#include <stdio.h>

// This code determines if a graph can be drawn based on the given degree sequence. 

#define numNodes 6
int degrees[numNodes] = {1, 4, 3, 5, 2, 3};

void swap(int d[], int a, int b){
    int temp = d[a];
    d[a] = d[b];
    d[b] = temp;
}

void insertionSort(int d[], int n){
    for (int i = 1; i < n; i++){
        for (int j = i; j > 0; j--){
            if (d[j - 1] < d[j]){
                swap(d, j, j - 1);
            }
            else
                break;
        }
    }
}

void printArr(int d[], int n){
    for (int i = 0; i < n; i++)
        printf("-%d--", d[i]);
}

int main(){
    insertionSort(degrees, numNodes);
    if (degrees[0] >= numNodes){
        printf("Graph cannot be drawn.");
    }
    else{
        for (int i = 0; i < numNodes; i++){
            insertionSort(degrees, numNodes);
            int temp = degrees[0];
            for (int m = 0; m < temp; m++){
                degrees[m + 1] = degrees[m + 1] - 1;
                degrees[0]--;
            }
        }
        if (degrees[0] == 0 && degrees[numNodes - 1] == 0){
            printf("Graph can be drawn.");
        }
        else{
            printf("Graph cannot be drawn.");
        }
    }
    return 0;
}
