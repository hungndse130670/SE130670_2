/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on June 5, 2020, 12:55 PM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 * 
 */

int cleanStdin() {
    while (getchar() != '\n') {
    }
    return 1;
}

int getNum() {
    int input;
    char c;
    int check;
    do {
        check = scanf("%d%c", &input, &c);
        if (check <= 0 || c != '\n') {
            printf("Error, please input again: ");
        }
    } while ((check <= 0 || c != '\n') && cleanStdin());
    return input;
}

void sortAsc(int arr[], int size) {
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(int argc, char** argv) {

    int size;
    do {
        printf("Enter size: ");
        size = getNum();
        if (size < 0) {
            printf("Error\n");
        }
    } while (size < 0);

    int array[size];
    for (int i = 0; i < size; i++) {
        printf("Element[%d]: ", i);
        array[i] = getNum();
    }

    if (size != 0) {
        sortAsc(array, size);
        printf("The array after sorting: \n");
        for (int i = 0; i < size; i++) {
            printf("%3d,", array[i]);
        }
        printf("\nEnter value: ");
        array[size] = getNum();
        size++;
        printf("New array: ");
        sortAsc(array, size);
        for (int i = 0; i < size; i++) {
            printf("%3d,", array[i]);
        }

    }

    return 0;
}

