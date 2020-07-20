/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on May 29, 2020, 1:50 PM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

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
            printf("Enter a positive number: ");
        }
    } while ((check <= 0 || c != '\n') && cleanStdin());
    return input;
}

void decToBin(int n) {
    int arr[n];
    int i = 0;
    while (n > 0) {
        arr[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", arr[j]);
    }
}

int main(int argc, char** argv) {

    int num;
    char c[255];
    char key;
    do {
        printf("Convert Dec to Bin program!\n");
        do {
            printf("Enter a positive number: ");
            num = inputInt();
            if (num < 0) {
                printf("Error\n");
            }
        } while (num < 0);

        printf("Binary number: ");
        if (num == 0) {
            printf("0");
        } else {
            decToBin(num);
        }

        printf("\nPress any key to continue the program, ESC to exit.\n");
        fgets(c, sizeof (c), stdin);
        key = c[0];
    } while (key != 27);

    return 0;
}

