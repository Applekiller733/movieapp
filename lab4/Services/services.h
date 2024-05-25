//
// Created by zelu on 22.03.2024.
//

#ifndef LAB4_SERVICES_H
#define LAB4_SERVICES_H

#include <string>
#include <exception>
#include "../Repository/repository.h"


class Services{

private:

    Repository& repo;

    std::string outputfileext;

    bool validate_movie(std::string title, int year);

    bool is_trailer_safe(std::string trailer) ;


public:
    explicit Services(Repository& repo);

    void populate_repo();

    bool add_s(std::string title, std::string genre, int year, int likes, std::string trailer);

    bool remove_s(std::string title, int year);

    bool update_s(std::string title, int year, std::string newtitle, std::string newgenre, int newyear, int newlikes, std::string newtrailer);

    bool add_watch_s(std::string title, std::string genre, int year, int likes, std::string trailer);

    std::vector<Movie>* getList_s();

    std::vector<Movie>* getwatchlist_s();

    std::vector<Movie> movies_by_genre(std::string genre);

    void set_output_type(std::string type);
    std::string get_outputfile_ext();

    std::string get_movies_filename_s();

    void read_from_file_s(std::vector<Movie>* v, std::string filename);
    void write_to_file_s(std::vector<Movie>* v, std::string filename);
};

#endif //LAB4_SERVICES_H
