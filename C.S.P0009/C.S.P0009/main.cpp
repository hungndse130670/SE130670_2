/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on May 25, 2020, 12:32 PM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */

double findMin(double arr[], int n) {
    double min = arr[0];
    for (int i = 0; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

void findPos(double arr[], int n) {
    int pos = 0;
    double min = findMin(arr, n);
    for (int i = 0; i < n; i++) {
        if (min == arr[i]) {
            pos = i;
            printf("The smallest element: %.2lf - Its position: %d \n ", min, pos);
        }
    }

}

//bool checkInt(char* str) {
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (!('0' <= str[i] && str[i] <= '9')) {
//            return false;
//        } else {
//            return true;
//        }
//    }
//}

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

//int charToInt(char *str) {
//    int res = 0;
//    for (int i = 0; str[i] != '\0'; i++) {
//        res = res * 10 + str[i];
//    }
//    return res;
//}

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

    if (size != 0) {
        findPos(array, size);
    }

    return 0;
}

