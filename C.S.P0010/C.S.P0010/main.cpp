/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on May 27, 2020, 2:02 PM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */

int deleteDup(double arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (arr[i] == arr[j]) { 
                for (int k = j; k < n; k++) { 
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
                count++;
            }
        }
    }
    return count;
}

void listArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf     ", arr[i]);
    }
    printf("\n");
}

int cleanStdin() {
    while (getchar() != '\n') {
    }
    return 1;
}

int inputInt() {
    int input;
    char c;
    int check;
    do {
        check = scanf("%d%c", &input, &c);
        if (check <= 0 || c != '\n') {
            printf("Error\n");
            printf("Enter size: ");
        }
    } while ((check <= 0 || c != '\n') && cleanStdin());
    return input;
}

double inputInt2(int i) {
    double input;
    char c;
    int check;
    do {
        check = scanf("%lf%c", &input, &c);
        if (check <= 0 || c != '\n') {
            printf("Error\n");
            printf("Element[%d]: ", i);
        }
    } while ((check <= 0 || c != '\n') && cleanStdin());
    return input;
}

int main(int argc, char** argv) {
    
    int size;
    do {
        printf("Enter size: ");
        size = inputInt();
        if (size < 0) {
            printf("Error\n");
        }
    } while (size < 0);

    double array[size];
    for (int i = 0; i < size; i++) {
        printf("Element[%d]: ", i);
        array[i] = inputInt2(i);
    }

    int count = 0;
    if (size != 0) {
        printf("The original array: \n");
        listArray(array, size);
        printf("\nThe array after removing duplicate elements: \n");
        count = deleteDup(array, size);
        size = size - count;
        listArray(array, size);
    }

    return 0;
}
