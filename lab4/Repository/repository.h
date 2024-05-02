//
// Created by ANDREI on 21-Mar-24.
//
#pragma once
#ifndef LAB4_REPOSITORY_H
#define LAB4_REPOSITORY_H

#include "../Domain/domain.h"
#include <string>
#include <iostream>


template <typename TElem> class DynamicVector{

    friend class Repository;
private:

    TElem* elems;
    int capacity;
    int size;

//    int findIndex(std::string title, int year);

    //void copyElem(int index, Movie elem);

    void debugPrint();

public:


    //default constructor
    DynamicVector();

    DynamicVector(int capacity); // param constructor

    void add(TElem mov);//adds movie to vector

    void resize();

    void remove(int index);//removes movie from vector

    void update(int index, TElem mov);

    TElem getElem(int index);

    int length();//returns vector size

    ~DynamicVector(); // destructor

};

template <typename TElem>
DynamicVector<TElem>::DynamicVector() {
    this->capacity = 10;
    this->elems = new Movie[this->capacity];
    this->size = 0;
}

template <typename TElem>
DynamicVector<TElem>::DynamicVector(int capacity) {
    this->capacity = capacity;
    this->elems = new Movie[this->capacity];
    this->size = 0;
}

template <typename TElem>
DynamicVector<TElem>::~DynamicVector() {
    delete[] this->elems;
}

template <typename TElem>
void DynamicVector<TElem>::debugPrint() {
    for(int i = 0; i < this->size; i++){
        std::cout << "Title: " << this->elems[i].getTitle() << "\n";
        std::cout << "Genre: " << this->elems[i].getGenre() << "\n";
        std::cout << "Year: " << this->elems[i].getYear() << "\n";
        std::cout << "Likes: " << this->elems[i].getLikes() << "\n";
        std::cout << "Trailer: " << this->elems[i].getTrailer() << "\n";
        std::cout <<"\n";
    }
}


template <typename TElem>
void DynamicVector<TElem>::resize() {
    this->capacity*=2;
    TElem* newElems = new TElem[this->capacity];
    for ( int i = 0; i < this->size; i++)
        newElems[i] = this->elems[i];
    delete[] this->elems;
    this->elems = newElems;
}

template <typename TElem>
void DynamicVector<TElem>::add(TElem mov) {
    if (this->size >= this->capacity){
        this->resize();
    }
    this->elems[this->size] = mov;
    this->size++;
}

template <typename TElem>
void DynamicVector<TElem>::remove(int index) {
    if (index != -1){
        for (int j = index; j < this->size - 1; j ++ ) {
            this->elems[j] = this->elems[j+1];
        }
        this->size--;
    }
}

template <typename TElem>
void DynamicVector<TElem>::update(int index, TElem mov) {
    this->elems[index] = mov;
}

template <typename TElem>
int DynamicVector<TElem>::length() {
    return this->size;
}

template <typename TElem>
TElem DynamicVector<TElem>::getElem(int index) {
    return this->elems[index];
}


class Repository{
    friend class DynamicVector <Movie>;
private:
    //DynamicVector <Movie> v;
    std::vector<Movie> v;
    std::vector<Movie> watchlist;
    //DynamicVector <Movie> watchlist;
public:

    //constructor
    Repository();

    int findIndex(std::string title, int year);



    bool inVector(std::string title, int year);//return true if movie in vector, false otherwise

    void add_repo(std::string title, std::string genre, int year, int likes, std::string trailer);

    void remove_repo(std::string title, int year);

    void update_repo(std::string title, int year, std::string newtitle, std::string newgenre,
                     int newyear, int newlikes,
                     std::string newtrailer);

    void add_to_watch(std::string title, std::string genre, int year, int likes, std::string trailer);

    std::vector <Movie>* getwatchlist();

    std::vector <Movie>* getList();

    //destructor
    ~Repository();
};

#endif //LAB4_REPOSITORY_H
