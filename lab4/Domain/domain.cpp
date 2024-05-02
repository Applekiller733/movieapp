//
// Created by ANDREI on 20-Mar-24.
//

#include "domain.h"
#include <stdlib.h>
#include <string.h>

Movie::Movie(){
    this->genre = new char[100];
    this->title = new char[100];
    this->trailer = new char[256];
}

Movie::Movie(char* title, char* genre, int year, int likes, char* trailer) {
    this->genre = new char[100];
    this->title = new char[100];
    this->trailer = new char[256];
    strcpy(this->title, title);
    strcpy(this->genre, genre);
    strcpy(this->trailer, trailer);
    this->year = year;
    this->likes = likes;
}

Movie::~Movie() {
    delete[] this->trailer;
    delete[] this->genre;
    delete[] this->title;
}

char *Movie::getTitle() {
    return this->title;
}

char *Movie::getGenre() {
    return this->genre;
}

int *Movie::getYear() {
    return &this->year;
}

int *Movie::getLikes() {
    return &this->likes;
}

char *Movie::getTrailer() {
    return this->trailer;
}

