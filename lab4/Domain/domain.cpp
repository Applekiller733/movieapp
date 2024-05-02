//
// Created by ANDREI on 20-Mar-24.
//

#include "domain.h"
#include <stdlib.h>
#include <string>
#include <string.h>

Movie::Movie(){
}

Movie::Movie(std::string title, std::string genre, int year, int likes, std::string trailer) {
    this->title = title;
    this->genre = genre;
    this->trailer = trailer;
    this->year = year;
    this->likes = likes;
}

Movie::~Movie() {
}

std::string Movie::getTitle() {
    return this->title;
}

void Movie::setTitle(std::string newtitle) {
    this->title = newtitle;
}

std::string Movie::getGenre() {
    return this->genre;
}

void Movie::setGenre(std::string newgenre) {
    this->genre = newgenre;
}

int Movie::getYear() {
    return this->year;
}

void Movie::setYear(int newyear) {
    this->year = newyear;
}

int Movie::getLikes() {
    return this->likes;
}

void Movie::setLikes(int newlikes) {
    this->likes = newlikes;
}

std::string Movie::getTrailer() {
    return this->trailer;
}

void Movie::setTrailer(std::string newtrailer){
    this->trailer = newtrailer;
}


