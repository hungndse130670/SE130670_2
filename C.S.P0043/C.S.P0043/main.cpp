/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on June 1, 2020, 1:24 PM
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

int getChoice() {
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

bool search(int arr[], int val, int size) {
    bool check = false;
    for (int i = 0; i < size; i++) {
        if (val == arr[i]) {
            printf("%3d,", i);
            check = true;
        }
    }
    return check;
}

int findPos(int arr[], int &size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

void removePos(int arr[], int &size, int val) {
    int pos = findPos(arr, size, val);
    if (pos == -1) {
        printf("Unable to find value\n");
    } else {
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        printf("Removed\n");
    }
}

void removeAll(int arr[], int &size) {
    printf("Enter value you want to delete: ");
    int val = getChoice();
    removePos(arr, size, val);
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
        }
    }
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

void sortDes(int arr[], int size) {
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void menu() {
    int choice;
    int count = 8;
    int arr[count];
    arr[0] = -7;
    arr[1] = 5;
    arr[2] = 5;
    arr[3] = 2;
    arr[4] = 2;
    arr[5] = 8;
    arr[6] = -1;
    arr[7] = 7;
    int array[count];
    int val;
    do {
        printf("\nArray Manipulations\n");
        printf("------------------------------\n");
        printf("1- Add a value\n");
        printf("2- Search a value\n");
        printf("3- Remove the first existence of a value\n");
        printf("4- Remove all existences of a value\n");
        printf("5- Print out the array\n");
        printf("6- Sort the array in ascending order (positions of elements are preserved)\n");
        printf("7- Sort the array in descending order (positions of elements are preserved)\n");
        printf("8- Quit\n");

        printf("Enter your choice: ");
        do {
            choice = getChoice();
            if (choice < 1 || choice > 8) {
                printf("Error\n");
            }
        } while (choice < 1 || choice > 8);

        switch (choice) {
            case 1: printf("1- Add a value\n");
                fflush(stdin);
                printf("Enter value: ");
                arr[count] = getChoice();
                printf("Added.");
                count++;
                for (int i = 0; i < count; i++) {
                    array[i] = arr[i];
                }
                printf("\n");
                break;
            case 2: printf("2- Search a value\n");
                fflush(stdin);
                printf("Enter value you want to search: ");
                val = getChoice();
                if (search(arr, val, count) == false) {
                    printf("Unable to find value");
                } else {
                    count--;
                }
                printf("\n");
                break;
            case 3: printf("3- Remove the first existence of a value\n");
                fflush(stdin);
                printf("Enter value you want to delete: ");
                val = getChoice();
                removePos(arr, count, val);
                for (int i = 0; i < count; i++) {
                    array[i] = arr[i];
                }
                printf("\n");
                break;
            case 4: printf("4- Remove all existences of a value\n");
                fflush(stdin);

                removeAll(arr, count);
                for (int i = 0; i < count; i++) {
                    array[i] = arr[i];
                }
                printf("\n");
                break;
            case 5: printf("5- Print out the array\n\n");
                fflush(stdin);
                for (int i = 0; i < count; i++) {
                    printf("%3d,", array[i]);
                }
                printf("\n");
                break;
            case 6: printf("6- Sort the array in ascending order (positions of elements are preserved)\n");
                fflush(stdin);
                sortAsc(arr, count);
                for (int i = 0; i < count; i++) {
                    printf("%3d,", arr[i]);
                }
                printf("\n");
                printf("\n");
                break;
            case 7: printf("7- Sort the array in descending order (positions of elements are preserved)\n");
                fflush(stdin);
                sortDes(arr, count);
                for (int i = 0; i < count; i++) {
                    printf("%3d,", arr[i]);
                }
                printf("\n");
                printf("\n");
                break;
            case 8:
                printf("\nSee you again!\n");
                break;

        }
    } while (choice != 8);
}

int main(int argc, char** argv) {

    menu();

    return 0;
}

