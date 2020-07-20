/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on June 22, 2020, 2:15 PM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

bool checkDate(int d, int m, int y) {
    int maxd = 31;
    if (d < 1 || d > 31 || m < 1 || m > 12) return false;
    if (m == 4 || m == 6 || m == 9 || m == 11) maxd = 30;
    else if (m == 2) {
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) maxd = 29;
        else maxd = 28;
    }
    if (d > maxd) return false;
    return true;
}

int dayOfYear(int y) {
    int result = 0;
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
        result = 366;
    } else result = 365;
    return result;
}

int dayOfMonth(int m, int y) {
    int result = 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) result = 30;
    else if (m == 2) {
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) result = 29;
        else result = 28;
    }
    return result;
}

int dayOfYear(int d, int m, int y) {
    int result = d;
    int feb = 28;
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) feb = 29;
    switch (m) {
        case 2:
            result = result + 31;
            break;
        case 3:
            result = result + 31 + feb;
            break;
        case 4:
            result = result + 31 + feb + 31;
            break;
        case 5:
            result = result + 31 + feb + 31 + 30;
            break;
        case 6:
            result = result + 31 + feb + 31 + 30 + 31;
            break;
        case 7:
            result = result + 31 + feb + 31 + 30 + 31 + 30;
            break;
        case 8:
            result = result + 31 + feb + 31 + 30 + 31 + 30 + 31;
            break;
        case 9:
            result = result + 31 + feb + 31 + 30 + 31 + 30 + 31 + 31;
            break;
        case 10:
            result = result + 31 + feb + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            break;
        case 11:
            result = result + 31 + feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            break;
        case 12:
            result = result + 31 + feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
            break;
    }
    return result;
}

int dayOfWeek(int day, int month, int year) {
    int result = 0;
    result = (day
            + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
            + (365 * (year + 4800 - ((14 - month) / 12)))
            + ((year + 4800 - ((14 - month) / 12)) / 4)
            - ((year + 4800 - ((14 - month) / 12)) / 100)
            + ((year + 4800 - ((14 - month) / 12)) / 400)
            - 32045) % 7;
    return result;
}

int weekOfYear(int d, int m, int y) {
    int day = dayOfYear(d, m, y);
    int dayWeek = dayOfWeek(d, m, y);
    int firstDay = dayOfWeek(01, 01, y);
    int result = (day + 6) / 7;
    if (dayWeek < firstDay) {
        result++;
    }
    return result;
}

int main(int argc, char** argv) {

    char date[10];
    int d, m, y, chars;
    int a;
    do {
        printf("Enter a date in format (dd/mm/yyyy): ");
        fgets(date, sizeof (date), stdin);
        a = sscanf(date, "%2d/%2d/%4d%n", &d, &m, &y, &chars);
        if ((a != 3) || (date[chars] != '\0' || !checkDate(d, m, y))) {
            printf("Invalid date\n");
        }
        if (y < 0) {
            printf("BC\n");
        }
    } while ((a != 3) || (date[chars] != '\0') || !checkDate(d, m, y));

    printf("Day of year: %d\n", dayOfYear(d, m, y));

    switch (dayOfWeek(d, m, y)) {
        case 0: printf("Day of week: Mon\n");
            break;
        case 1: printf("Day of week: Tue\n");
            break;
        case 2: printf("Day of week: Wed\n");
            break;
        case 3: printf("Day of week: Thus\n");
            break;
        case 4: printf("Day of week: Fri\n");
            break;
        case 5: printf("Day of week: Sat\n");
            break;
        case 6: printf("Day of week: Sun\n");
            break;

    }

    printf("Week of year: %d\n", weekOfYear(d, m, y));

    return 0;
}

