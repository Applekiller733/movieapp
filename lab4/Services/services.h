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

    Repository repo;

    bool validate_movie(std::string title, int year);

    bool is_trailer_safe(std::string trailer) ;

public:

    bool add_s(std::string title, std::string genre, int year, int likes, std::string trailer);

    bool remove_s(std::string title, int year);

    bool update_s(std::string title, int year, std::string newtitle, std::string newgenre, int newyear, int newlikes, std::string newtrailer);

    bool add_watch_s(std::string title, std::string genre, int year, int likes, std::string trailer);

    std::vector<Movie>* getList_s();

    std::vector<Movie>* getwatchlist_s();

    std::vector<Movie> movies_by_genre(std::string genre);

    void read_from_json(std::string typelist, std::string filename);
    void write_to_json(std::string typelist, std::string filename);

    void write_to_csv(std::string filename);
    void write_to_html(std::string filename);

    void debg_write();
};

#endif //LAB4_SERVICES_H
