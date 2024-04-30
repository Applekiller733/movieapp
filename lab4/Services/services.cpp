//
// Created by zelu on 22.03.2024.
//

#include "services.h"
#include "../Repository/repository.h";
#include "../nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <regex>

bool Services::validate_movie(std::string title, int year) {
    return !this->repo.inVector(title, year);
}

bool Services::is_trailer_safe(std::string trailer) {
    std::regex regexp("^https://www.youtube.com/.*");
    if (std::regex_search(trailer,regexp)) {
        return true;
    }
    return false;
}

bool Services::add_s(std::string title, std::string genre, int year, int likes, std::string trailer) {
    if (this->validate_movie(title, year) && this->is_trailer_safe(trailer)) {
        this->repo.add_repo(title, genre, year, likes, trailer);
        return true;
    }
    return false;
}

bool Services::remove_s(std::string title, int year) {
    if (!this->validate_movie(title, year)) {
        this->repo.remove_repo(title, year);
        return true;
    }
    return false;
}

bool
Services::update_s(std::string title, int year, std::string newtitle, std::string newgenre,
                   int newyear, int newlikes,
                   std::string newtrailer) {
    if(!this->validate_movie(title, year))
    {
        this->repo.update_repo(title, year, newtitle, newgenre, newyear, newlikes, newtrailer);
        return true;
    }
    return false;
}

std::vector<Movie>* Services::getList_s() {
    return this->repo.getList();
}

std::vector<Movie> *Services::getwatchlist_s() {
    return this->repo.getwatchlist();
}

std::vector<Movie> Services::movies_by_genre(std::string genre) {
    std::vector<Movie>* v = this->getList_s();
    std::vector<Movie> res;
    for ( int ind = 0; ind < v->size(); ind++)
    {
        Movie mov = v->at(ind);
        if ( mov.getGenre() == genre || genre == "")
            res.push_back(mov);
    }
    return res;
}

bool Services::add_watch_s(std::string title, std::string genre, int year, int likes, std::string trailer) {
    this->repo.add_to_watch(title, genre, year, likes, trailer);
}

void Services::write_to_json(std::string typelist, std::string filename) {
    std::vector<Movie>* v;
    if (typelist == "movielist")
        v = this->getList_s();
    else if (typelist == "watchlist")
        v = this->getwatchlist_s();
    else
        return;

    nlohmann::json jarr = nlohmann::json::array();
    for (int i=0; i < v->size(); i++){
        nlohmann::json obj;
        Movie mov = v->at(i);
        obj["title"] = mov.getTitle();
        obj["genre"] = mov.getGenre();
        obj["year"] = mov.getYear();
        obj["likes"] = mov.getLikes();
        obj["trailer"] = mov.getTrailer();
        jarr.push_back(obj);
    }

    if (typelist == "movielist") {
        std::ofstream out("/home/zelu/CLionProjects/OOP/lab4/JSONsaves/"+filename);
        out << jarr;
        out.close();
    }
    else{
        std::ofstream out("/home/zelu/CLionProjects/OOP/lab4/JSONsaves/"+filename);
        out << jarr;
        out.close();
    }
}

void Services::read_from_json(std::string typelist, std::string filename) {

        nlohmann::json jarr = nlohmann::json::array();
        if (typelist == "movielist") {
            std::ifstream in("/home/zelu/CLionProjects/OOP/lab4/JSONsaves/"+filename);
            jarr = nlohmann::json::parse(in);
            in.close();
            for (auto i = jarr.begin(); i < jarr.end(); i++){
                this->add_s(i->at("title").get<std::string>(),i->at("genre").get<std::string>(),
                            i->at("year").get<int>(), i->at("likes").get<int>(),
                            i->at("trailer").get<std::string>());
            }
        }
        else if (typelist == "watchlist"){
            std::ifstream in("/home/zelu/CLionProjects/OOP/lab4/JSONsaves/"+filename);
            jarr = nlohmann::json::parse(in);
            in.close();
            for (auto i = jarr.begin(); i < jarr.end(); i++){
                this->add_watch_s(i->at("title").get<std::string>(),i->at("genre").get<std::string>(),
                            i->at("year").get<int>(), i->at("likes").get<int>(),
                            i->at("trailer").get<std::string>());
            }
        }
        else
            return;

}


