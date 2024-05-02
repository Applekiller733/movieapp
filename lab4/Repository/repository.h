//
// Created by ANDREI on 21-Mar-24.
//
#pragma once
#ifndef LAB4_REPOSITORY_H
#define LAB4_REPOSITORY_H

#include "../Domain/domain.h"

class DynamicVector{

private:
    Movie* elems;
    int capacity;
    int size;

    int findIndex(char* title, int year);

    void copyElem(int index, Movie elem);

    void debugPrint();

public:
    DynamicVector(int capacity); // constructor

    void add(Movie mov);

    void remove(char* title, int year);

    int length();

    ~DynamicVector(); // destructor

};

// todo class Repository, contains dynamic vector as watch list and one as database

#endif //LAB4_REPOSITORY_H
