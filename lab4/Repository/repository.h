//
// Created by ANDREI on 21-Mar-24.
//
#pragma once
#ifndef LAB4_REPOSITORY_H
#define LAB4_REPOSITORY_H

#include "../Domain/domain.h"
#include <string>
#include <iostream>

class RepositoryException : public std::exception{
private:
    std::string message;
public:
    RepositoryException(const std::string message);
    std::string getMessage() const;
};

class Repository{
private:
    //DynamicVector <Movie> v;
    std::vector<Movie> v;
    std::vector<Movie> watchlist;
    std::string outputfileext;
    std::string moviesfilename;
    //DynamicVector <Movie> watchlist;
public:

    //constructor
    Repository(std::string filename); // add filename constructor for polymorphism

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

    std::string get_outputfile_ext();
    void set_output_type(std::string type);

    std::string get_movies_filename();

    virtual void write_to_file(std::vector<Movie>* v, std::string filename);
    virtual void read_from_file(std::vector<Movie>* v, std::string filename);

//    virtual void save_movielist(std::string filename);
//    virtual void save_watchlist(std::string filename);
//
//    void write_to_csv(std::string filename);
//    void write_to_html(std::string filename);

    //destructor
    ~Repository();
};
//todo add 2 inherited classes for html/csv
//

class CSVRepository : public Repository{
public:
    CSVRepository(std::string filename);
    void write_to_file(std::vector<Movie>* v, std::string filename) override;
    void read_from_file(std::vector<Movie>* v, std::string filename) override;
};

class HTMLRepository : public Repository{
public:
    HTMLRepository(std::string filename);
    void write_to_file(std::vector<Movie>* v, std::string filename) override;
};


#endif //LAB4_REPOSITORY_H
