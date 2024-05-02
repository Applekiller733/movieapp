//
// Created by ANDREI on 20-Mar-24.
//

//#include <string>
#include <string.h>
#include <iostream>

#include <string>
#include <cctype>
#include "ui.h"




UI::UI() {

}

int UI::wordcnt(const char *sentence){
    if (sentence == NULL)
        return -1;
    int cnt = 0;
    bool inspace = true;
    while(*sentence != '\0'){
        if (std::isspace(*sentence)){
            inspace = true;
        }
        else{
            if (inspace == true)
                cnt++;
            inspace = false;
        }
        ++sentence;
    }
    return cnt;
}

void UI::start() {
    bool cond = true;
    while (cond) {
        char *str = (char*)malloc(sizeof(char) * 6);
        std::cout << "Which mode do you wish to access?\n";
        std::cin.getline(str, 6);
        if (strcmp(str, "1") == 0 || strcmp(str, "admin") == 0) {
            cond = false;
            this->adminmode();

        } else if (strcmp(str, "2") == 0 || strcmp(str, "user") == 0) {
            cond = false;
            this->usermode();

        } else
            std::cout << "Invalid input\n";
    }

}

void UI::adminmode() {

    char* command = (char*)malloc(sizeof(char)*7);
    char* title = (char*)malloc(sizeof(char)*100);
    char* genre = (char*)malloc(sizeof(char)*100);
    int year;
    int likes;
    char* trailer = (char*)malloc(sizeof(char)*256);

    while (true) {

        std::cout << "Admin cmmd:>";
        std::cin.getline(command, 7);
        //todo figure out why if inputting empty line, it crashes (mem access violation)
        if (strcmp(command, "add") == 0){
            std:: cout <<"Title: ";
            std::cin.getline(title, 100);
            std::cout << "Genre: ";
            std::cin.getline(genre, 100);
            std::cout << "Year: ";
            std::cin >> year;
            std::cout << "Likes: ";
            std::cin >> likes;
            std::cin.ignore(1);
            std::cout << "Trailer: ";
            std::cin.getline(trailer, 256);


            //todo add validator
            //todo add function
        }
        else if (strcmp(command, "remove") == 0 || strcmp(command, "rmv") == 0){

            std::cout << "Title: ";
            std::cin.getline(title, 100);
            std::cout << "Year: ";
            std::cin >> year;
            std::cin.ignore(1);

            //todo add validator
            //todo add func
        }
        else if (strcmp(command, "update") == 0 || strcmp(command, "updt") == 0){
            std::cout << "Title: ";
            std::cin.getline(title, 100);
            std::cout << "Year: ";
            std::cin >> year;
            std::cin.ignore(1);


            std::cout << "Insert new data/>\n";
            char* newtitle = (char*)malloc(sizeof(char)*100);
            char* newgenre = (char*)malloc(sizeof(char)*100);
            char* newtrailer = (char*)malloc(sizeof(char)*256);
            int newyear;
            int newlikes;

            std::cout <<"New Title: ";
            std::cin.getline(newtitle, 100);
            std::cout << "New Genre: ";
            std::cin.getline(newgenre, 100);
            std::cout << "New Year: ";
            std::cin >> newyear;
            std::cin.ignore(1);
            std::cout << "New Likes: ";
            std::cin >> newlikes;
            std::cin.ignore(1);

            //todo finish
        }
        else if (strcmp(command, "help") == 0){
            std::cout << "List of commands:\n"
                         "\t1. add\n"
                         "\t2.remove || rmv \n"
                         "\t3.update || updt \n"
                         "\t4.list || ls \n"
                         "\t5.exit || q \n";
        }
        else if (strcmp(command, "list") == 0 || strcmp(command, "ls") == 0){

            //todo add connection to services/repo list
        }
        else if (strcmp(command, "exit") == 0 || strcmp(command, "q") == 0){
            exit(0);
        }
        else
            std::cout<<"Invalid command\n";
    }
}

void UI::usermode() {
    while(true){
        std::cout << "Welcome to the movie app!\n"
                     "\t1.See movies by genre\n"
                     "\t2.See watch list\n"
                     "\t3.Exit\n";
        int inp = -1;
        std::cin >> inp;
        if (inp == 1){
        //todo load movies by genre one by one
        //todo add the other functionalities
        }
        else if (inp == 2){
        //todo see watch list
        }
        else if (inp == 3){
            exit(0);
        }
    }
}

UI::~UI() {

}