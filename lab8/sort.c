#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateKnuthSequence(int n, int sequence[], int *size) {
    int h = 1, i = 0;
    while (h < n) {
        sequence[i++] = h;
        h = 3 * h + 1;}
    *size = i;}

void shellSort(int arr[], int n, int *M, int *C) {
    int sequence[20], size;
    generateKnuthSequence(n, sequence, &size);
    
    for (int g = size - 1; g >= 0; g--) {
        int gap = sequence[g];
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            (*M)++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                (*C)++;
                arr[j] = arr[j - gap];
                (*M)++;}
            arr[j] = temp;
            (*M)++;}}}

void insertionSort(int arr[], int n, int *M, int *C) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        (*M)++;
        while (j >= 0 && arr[j] > temp) {
            (*C)++;
            arr[j + 1] = arr[j];
            (*M)++;
            j--;}
        arr[j + 1] = temp;
        (*M)++;}}

void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;}}
