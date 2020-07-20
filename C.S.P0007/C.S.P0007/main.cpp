/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: duchu
 *
 * Created on May 22, 2020, 10:35 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {

    char words[1000];
    char remove[1000];

    int i;
    do {
        printf("Enter an string, do not allow enter special characters such as @, #, !, [, ], {, }, (, )\n");
        fflush(stdin);
        fgets(words, sizeof (words), stdin);
        for(int i = 0; i < sizeof(words); i++);
    } while (words[i] == '@' || words[i] == '#' || words[i] == '!' || words[i] == '[' 
            || words[i] == ']' || words[i] == '{' || words[i] == '}' || words[i] == '(' || words[i] == ')');

    while (words[0] == ' ') strcpy(&words[0], &words[1]);
    while (words[strlen(words) - 1] == ' ') words[strlen(words) - 1] = '\0';
    int w = 0, r = 0;
    while (words[w] != '\0') {
        if (!(words[w] == ' ' && words[w + 1] == ' ')) {
            remove[r] = words[w];
            r++;
            //cho chuỗi words chạy từ vị trí đầu là 0 đến cuối là null: \0
            //nếu kí tự i và i+1 ko tồn tại 2 dấu cách liên tục
            //thì gán kí tự i cho remove
        }
        w++;
    }
    printf("The string after removing: \n");   
    puts(remove);
    return 0;
    
}

