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

    void initialize_repo();

public:
    UI(); //constructor

    void login();

    void start();

    void adminmode();

    void usermode();

    void filesavemovies();
    void filesavewatch();

    ~UI(); //destructor
};
#endif //LAB4_UI_H
