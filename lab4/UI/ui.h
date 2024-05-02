//
// Created by ANDREI on 20-Mar-24.
//
#pragma once
#ifndef LAB4_UI_H
#define LAB4_UI_H

#include "../Services/services.h"

class UI {

private:
    //int wordcnt(const char* sentence);

    Services serv;

    std::string outputfiletype;

    void initialize_repo();

    void savemovies();
    void savewatch();

public:
    UI(); //constructor

    void login();

    void start();

    void adminmode();

    void usermode();

    ~UI(); //destructor
};
#endif //LAB4_UI_H
