//
// Created by ANDREI on 21-Mar-24.
//

#include "repository.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../nlohmann/json.hpp"


//Dynamic Vector
DynamicVector::DynamicVector() {
    this->capacity = 10;
    this->elems = new Movie[this->capacity];
    this->size = 0;
}

DynamicVector::DynamicVector(int capacity) {
    this->capacity = capacity;
    this->elems = new Movie[this->capacity];
    this->size = 0;
}

DynamicVector::~DynamicVector() {
    delete[] this->elems;
}

void DynamicVector::debugPrint() {
    for(int i = 0; i < this->size; i++){
        std::cout << "Title: " << this->elems[i].getTitle() << "\n";
        std::cout << "Genre: " << this->elems[i].getGenre() << "\n";
        std::cout << "Year: " << this->elems[i].getYear() << "\n";
        std::cout << "Likes: " << this->elems[i].getLikes() << "\n";
        std::cout << "Trailer: " << this->elems[i].getTrailer() << "\n";
        std::cout <<"\n";
    }
}

int DynamicVector::findIndex(std::string title, int year) {
    for(int i = 0; i < this->size; i++){
        if (this->elems[i].getTitle() == title && this->elems[i].getYear() == year)
            return i;
    }
    return -1;
}

void DynamicVector::add(Movie mov) {
    if (this->size >= this->capacity){
        this->capacity++;

        Movie* newElems = new Movie[this->capacity];

        for (int i = 0; i < this->size; i++)
        {
            newElems[i].setTitle(this->elems[i].getTitle());
            newElems[i].setGenre(this->elems[i].getGenre());
            newElems[i].setTrailer(this->elems[i].getTrailer());
            newElems[i].setYear(this->elems[i].getYear());
            newElems[i].setLikes(this->elems[i].getLikes());
        }

        //std::cout << "successfully moved elems\n";
        delete[] this->elems;
        //std::cout << "successfully deleted old array\n";
        this->elems = newElems;
        //std::cout << "successfully reallocated array\n";
    }
    this->elems[this->size].setTitle(mov.getTitle());
    this->elems[this->size].setGenre(mov.getGenre());
    this->elems[this->size].setTrailer(mov.getTrailer());
    this->elems[this->size].setYear(mov.getYear());
    this->elems[this->size].setLikes(mov.getLikes());

    //std::cout << "successfully added new element\n";
    this->size++;
    //this->debugPrint();
}

void DynamicVector::remove(std::string title, int year) {
    int ind = this->findIndex(title, year);
    if (ind != -1){
        for (int j = ind; j < this->size - 1; j ++ ) {
            this->elems[j].setTitle(this->elems[j+1].getTitle());
            this->elems[j].setGenre(this->elems[j+1].getGenre());
            this->elems[j].setTrailer(this->elems[j+1].getTrailer());
            this->elems[j].setYear(this->elems[j+1].getYear());
            this->elems[j].setLikes(this->elems[j+1].getLikes());
        }
        this->size--;
    }
}

void DynamicVector::update(std::string title, int year, std::string newtitle, std::string newgenre, int newyear,
                           int newlikes, std::string newtrailer) {
    int ind = this->findIndex(title, year);
    this->elems[ind].setTitle(newtitle);
    this->elems[ind].setGenre(newgenre);
    this->elems[ind].setYear(newyear);
    this->elems[ind].setLikes(newlikes);
    this->elems[ind].setTrailer(newtrailer);
}

int DynamicVector::length() {
    return this->size;
}

Movie DynamicVector::getElem(int index) {
    return this->elems[index];
}





//Repository

Repository::Repository() {

}

Repository::~Repository() {

}

DynamicVector* Repository::getList() {
    return &this->v;
}

DynamicVector *Repository::getwatchlist() {
    return &this->watchlist;
}

bool Repository::inVector(std::string title, int year) {
    if(this->v.findIndex(title, year) != -1)
        return true;
    return false;
}

void Repository::add_repo(std::string title, std::string genre, int year, int likes, std::string trailer) {
    Movie newmov(title, genre, year, likes, trailer);
    this->v.add(newmov);
}

void Repository::remove_repo(std::string title, int year) {
    this->v.remove(title, year);
}

void Repository::update_repo(std::string title, int year, std::string newtitle, std::string newgenre, int newyear,
                             int newlikes, std::string newtrailer) {
    this->v.update(title, year, newtitle, newgenre, newyear, newlikes, newtrailer);
}

void Repository::add_to_watch(std::string title, std::string genre, int year, int likes, std::string trailer) {
    Movie newmov(title, genre, year, likes, trailer);
    this->watchlist.add(newmov);
}
