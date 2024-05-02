//
// Created by ANDREI on 20-Mar-24.
//

#ifndef LAB4_DOMAIN_H
#define LAB4_DOMAIN_H

class Movie{

private:
    char* title;
    char* genre;
    int year;
    int likes;
    char* trailer;

public:


    Movie();

    //constructor
    Movie(char* title, char* genre, int year, int likes, char* trailer);

    char* getTitle();
    char* getGenre();
    int* getYear();
    int* getLikes();
    char* getTrailer();

    //destructor
    ~Movie();

};

#endif //LAB4_DOMAIN_H
