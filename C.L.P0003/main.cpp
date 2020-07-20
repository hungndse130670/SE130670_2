/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on June 17, 2020, 2:11 PM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

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

int play() {
    int n1 = rand() % 10;
    int n2 = rand() % 10;
    int n3 = rand() % 10;
    int i = rand() % 2;
    if (i == 1) {
        n1 = rand() % 10;
        n2 = n1;
        n3 = n1;
        printf("The slot machine shows: %d%d%d.\n", n1, n2, n3);
        return 1;
    } else {
        printf("The slot machine shows: %d%d%d.\n", n1, n2, n3);
        if (n1 == n2 && n1 == n3) {
            return 2;
        } else {
            return 0;
        }
    }
}

void saveFile(float money) {
    FILE *f = fopen("C.L.P0003.txt", "w");
    fprintf(f, "%.2f", money);
    fclose(f);
}

float openFile() {
    float money;
    FILE *f = fopen("C.L.P0003.txt", "r");
    fscanf(f, "%f", &money);
    fclose(f);
    return money;
}

void menu(float money) {
    int choice;
    int n;
    do {
        printf("You have $%.2f.\n\n", money);
        printf("Choose one of the following menu options: \n");
        printf("1. Play the slot machine.\n");
        printf("2. Save game.\n");
        printf("3. Cash out.\n\n");
        printf("Enter your choice(1..3): ");
        do {
            choice = getChoice();
            if (choice < 1 || choice > 3) {
                printf("Error\n");
            }
        } while (choice < 1 || choice > 3);
        printf("\n");

        switch (choice) {
            case 1:
                while (money != 0) {
                    n = play();
                    printf("You have: $%.2f\n", money);
                    if (n == 1) {
                        printf("You won 50 cents!\n");
                        money = money + 0.50 - 0.25;
                    } else if (n == 2) {
                        printf("You won the big prize, $10.00\n");
                        money = money + 10 - 0.25;
                    } else {
                        printf("Sorry, you didn't win anything!\n");
                        money = money - 0.25;
                    }
                }

                if (money == 0) {
                    printf("\nYou have no money!!!\n");
                    saveFile(money);
                    choice = 3;
                }
                break;
            case 2: saveFile(money);
                printf("Your money had saved!\n");
                break;
            case 3: printf("Thanks for playing! You end with: $%.2f", money);
                break;
        }
    } while (choice != 3);

}

int main(int argc, char** argv) {
    float money = 10;
    float n;
    n = openFile();

    if (n != 0) {
        money = n;
        printf("Welcome back!\n");
        menu(money);
    } else {
        printf("Welcome!\n");
        menu(money);
    }

    return 0;
}

