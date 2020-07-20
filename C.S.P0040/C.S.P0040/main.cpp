/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on June 1, 2020, 10:34 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>

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

double getNum() {
    double input;
    char c;
    int check;
    do {
        check = scanf("%lf%c", &input, &c);
        if (check <= 0 || c != '\n') {
            printf("Error, please input again: ");
        }
    } while ((check <= 0 || c != '\n') && cleanStdin());
    return input;
}

void quadEquation(double a, double b, double c) {
    double x1 = 0;
    double x2 = 0;
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        printf("No solution");
    } else if (delta == 0) {
        printf("This quadratic equation has one solution:\nx = %.2lf", (-b / (2 * a)));
    } else {
        delta = sqrt(delta);
        x1 = (-b + delta) / (2 * a);
        x2 = (-b - delta) / (2 * a);
        printf("This quadratic equation has two solutions:\nx1 = %.2lf\nx2 = %.2lf", x1, x2);
    }

}

void quadratic() {
    double a, b, c;
    printf("Input coefficients a, b, and c of a quadratic equation: \n");
    printf("Coefficient a: ");
    a = getNum();
    printf("Coefficient b: ");
    b = getNum();
    printf("Coefficient c: ");
    c = getNum();
    printf("a = %.2lf | b = %.2lf | c = %.2lf\n", a, b, c);
    if (a == 0 && b == 0 && c == 0) {
        printf("Infinite solutions");
    } else if (a == 0 && b == 0 && c != 0) {
        printf("No solution");
    } else if (a == 0 && b != 0 && c != 0) {
        printf("This quadratic equation has one solution:\nx = %.2lf", (-c / b));
    } else if (a != 0 && b != 0 && c != 0) {
        quadEquation(a, b, c);
    }
}

long int getDeposit() {
    long int input;
    char c;
    int check;
    do {
        check = scanf("%ld%c", &input, &c);
        if (check <= 0 || c != '\n') {
            printf("Error, please input again: ");
        }
    } while ((check <= 0 || c != '\n') && cleanStdin());
    return input;
}

void bankDeposit() {
    long int deposit;
    double rate;
    int month;
    double total;
    printf("Deposits (a positive number): ");

    do {
        deposit = getDeposit();
        if (deposit <= 0) {
            printf("Error (Deposit must be a positive number)\n");
            printf("Please input again: ");
        }
    } while (deposit <= 0);

    printf("Deposit interest rates (a positive number <= 10): ");
    do {
        rate = getNum();
        if (rate <= 0 || rate > 10) {
            printf("Error (Deposit interest rates (a positive number <= 10))\n");
            printf("Please input again: ");
        }
    } while (rate <= 0 || rate > 10);

    printf("Number of deposit months (a positive number): ");
    do {
        month = getChoice();
        if (month < 0) {
            printf("Error (Number of deposit months (a positive number))\n");
            printf("Please input again: ");
        }
    } while (month < 0);

    total = deposit * rate * month /100;
    printf("The total amount received: %.5lf", total);
}

void menu() {
    int choice;

    do {
        printf("\nMENU\n");
        printf("------------------------------\n");
        printf("1. Quadratic equation\n");
        printf("2. Bank deposit problem\n");
        printf("3. Quit.\n");
        printf("Enter your choice: ");
        do {
            choice = getChoice();
            if (choice < 1 || choice > 3) {
                printf("Error\n");
            }
        } while (choice < 1 || choice > 3);

        switch (choice) {
            case 1: printf("\n1. Quadratic equation\n");
                fflush(stdin);
                quadratic();
                printf("\n");
                break;
            case 2: printf("\n2. Bank deposit problem\n");
                fflush(stdin);
                bankDeposit();
                printf("\n");
                break;
            case 3:
                printf("\nSee you again!\n");
                break;
        }
    } while (choice != 3);
}

int main(int argc, char** argv) {

    menu();

    return 0;
}

