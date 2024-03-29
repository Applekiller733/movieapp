//
// Created by ANDREI on 21-Mar-24.
//
#pragma once
#ifndef LAB4_REPOSITORY_H
#define LAB4_REPOSITORY_H

#include "../Domain/domain.h"
#include <string>



class DynamicVector{

    friend class Repository;
private:

    Movie* elems;
    int capacity;
    int size;

    int findIndex(std::string title, int year);

    void copyElem(int index, Movie elem);

    void debugPrint();

public:


    //default constructor
    DynamicVector();

    DynamicVector(int capacity); // param constructor

    void add(Movie mov);//adds movie to vector

    void remove(std::string title, int year);//removes movie from vector

    void update(std::string title, int year, std::string newtitle, std::string newgenre, int newyear,
                int newlikes, std::string newtrailer);

    Movie getElem(int index);

    int length();//returns vector size

    ~DynamicVector(); // destructor

};


class Repository{
    friend class DynamicVector;
private:
    DynamicVector v;

    DynamicVector watchlist;
public:

    //constructor
    Repository();

    bool inVector(std::string title, int year);//return true if movie in vector, false otherwise

    void add_repo(std::string title, std::string genre, int year, int likes, std::string trailer);

    void remove_repo(std::string title, int year);

    void update_repo(std::string title, int year, std::string newtitle, std::string newgenre,
                     int newyear, int newlikes,
                     std::string newtrailer);

    void add_to_watch(std::string title, std::string genre, int year, int likes, std::string trailer);

    DynamicVector* getwatchlist();

    DynamicVector* getList();

    //destructor
    ~Repository();
};
// todo class Repository, contains dynamic vector as watch list and one as database

#endif //LAB4_REPOSITORY_H
