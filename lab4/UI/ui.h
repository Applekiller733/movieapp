//
// Created by ANDREI on 20-Mar-24.
//
#pragma once
#ifndef LAB4_UI_H
#define LAB4_UI_H

class UI {

private:
    int wordcnt(const char* sentence);
public:
    UI(); //constructor

    void start();

    void adminmode();

    void usermode();

    ~UI(); //destructor
};
#endif //LAB4_UI_H
