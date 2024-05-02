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






//Repository

Repository::Repository() {

}

Repository::~Repository() {

}

std::vector<Movie>* Repository::getList() {
    return &this->v;
}

std::vector<Movie> *Repository::getwatchlist() {
    return &this->watchlist;
}

int Repository::findIndex(std::string title, int year) {
    for ( int i = 0; i < this->getList()->size(); i ++){
        if (this->v[i].getTitle() == title && this->v[i].getYear() == year)
            return i;
    }
    return -1;
}

bool Repository::inVector(std::string title, int year) {
    if(this->findIndex(title, year) != -1)
        return true;
    return false;
}

void Repository::add_repo(std::string title, std::string genre, int year, int likes, std::string trailer) {
    Movie newmov(title, genre, year, likes, trailer);
    this->v.push_back(newmov);
}

void Repository::remove_repo(std::string title, int year) {
    int index = this->findIndex(title, year);
    this->v.erase(v.begin()+index);
}

void Repository::update_repo(std::string title, int year, std::string newtitle, std::string newgenre, int newyear,
                             int newlikes, std::string newtrailer) {
    int index = this->findIndex(title, year);
    Movie newmov(newtitle, newgenre, newyear, newlikes, newtrailer);
    this->v[index] = newmov;
}

void Repository::add_to_watch(std::string title, std::string genre, int year, int likes, std::string trailer) {
    Movie newmov(title, genre, year, likes, trailer);
    this->watchlist.push_back(newmov);
}
