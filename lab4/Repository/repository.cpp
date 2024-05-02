//
// Created by ANDREI on 21-Mar-24.
//

#include "repository.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

DynamicVector::DynamicVector(int capacity) {
    this->elems = new Movie[this->capacity];
    this->capacity = capacity;
    this->size = 0;
}

DynamicVector::~DynamicVector() {
    delete[] this->elems;
}

void DynamicVector::debugPrint() {
    for(int i = 0; i < this->size; i++){
        std::cout << "Title: " << this->elems[i].getTitle() << "\n";
        std::cout << "Genre: " << this->elems[i].getGenre() << "\n";
        std::cout << "Year: " << *this->elems[i].getYear() << "\n";
        std::cout << "Likes: " << *this->elems[i].getLikes() << "\n";
        std::cout << "Trailer: " << this->elems[i].getTrailer() << "\n";
        std::cout <<"\n";
    }
}

int DynamicVector::findIndex(char *title, int year) {
    for(int i = 0; i < this->size; i++){
        if (strcmp(this->elems[i].getTitle(), title) == 0 && *this->elems[i].getYear() == year)
            return i;
    }
    return -1;
}

void DynamicVector::copyElem(int index, Movie elem) {
    strcpy(this->elems[index].getTitle(), elem.getTitle());
    strcpy(this->elems[index].getGenre(), elem.getGenre());
    strcpy(this->elems[index].getTrailer(), elem.getTrailer());
    *this->elems[index].getYear() = *elem.getYear();
    *this->elems[index].getLikes() = *elem.getLikes();
}

void DynamicVector::add(Movie mov) {

    if (this->size >= this->capacity){
        this->capacity++;

        Movie* newElems = new Movie[this->capacity];

        for (int i = 0; i < this->size; i++)
        {
            strcpy(newElems[i].getTitle(), this->elems[i].getTitle());
            strcpy(newElems[i].getGenre(), this->elems[i].getGenre());
            strcpy(newElems[i].getTrailer(), this->elems[i].getTrailer());
            *newElems[i].getYear() = *this->elems[i].getYear();
            *newElems[i].getLikes() = *this->elems[i].getLikes();
        }

        std::cout << "successfully moved elems\n";
        delete[] this->elems;
        std::cout << "successfully deleted old array\n";
        this->elems = newElems;
        std::cout << "successfully reallocated array\n";
    }
    //this->copyElem(this->size, mov);
    strcpy(this->elems[this->size].getTitle(), mov.getTitle());
    strcpy(this->elems[this->size].getGenre(), mov.getGenre());
    strcpy(this->elems[this->size].getTrailer(), mov.getTrailer());
    *this->elems[this->size].getYear() = *mov.getYear();
    *this->elems[this->size].getLikes() = *mov.getLikes();

    std::cout << "successfully added new element\n";
    this->size++;
    this->debugPrint();

}

void DynamicVector::remove(char* title, int year) {
    int ind = this->findIndex(title, year);
    if (ind != -1){

        for (int j = ind; j < this->size - 1; j ++ )
            this->copyElem(j, this->elems[j+1]);

        this->size--;
    }
}

int DynamicVector::length() {
    return this->size;
}
