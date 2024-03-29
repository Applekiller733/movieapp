//
// Created by ANDREI on 20-Mar-24.
//

#ifndef LAB4_DOMAIN_H
#define LAB4_DOMAIN_H

#include <string>
#include "../nlohmann/json.hpp"


class Movie{

private:
    std::string title;
    std::string genre;
    int year;
    int likes;
    std::string trailer;

public:

    //default constructor
    Movie();

    //param constructor
    Movie(std::string title, std::string genre, int year, int likes, std::string trailer);

    //getters
    std::string getTitle();
    std::string getGenre();
    int getYear();
    int getLikes();
    std::string getTrailer();

    //setters
    void setTitle(std::string newtitle);
    void setGenre(std::string newgenre);
    void setYear(int newyear);
    void setLikes(int newlikes);
    void setTrailer(std::string newtrailer);

    //destructor
    ~Movie();
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Movie, title, genre, year, likes, trailer)
};

#endif //LAB4_DOMAIN_H
