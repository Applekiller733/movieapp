//
// Created by zelu on 22.03.2024.
//

#include "services.h"
#include "../Repository/repository.h"
#include "../nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <regex>
#include <filesystem>


Services::Services(Repository& repo) : repo{repo}{

}

void Services::populate_repo() {

    this->add_s("Dune", "science fiction", 2021, 679000, "https://www.youtube.com/watch?v=n9xhJrPXop4");
    this->add_s("Whiplash", "drama", 2015, 65000, "https://www.youtube.com/watch?v=7d_jQycdQGo");
    this->add_s("Fight Club", "thriller", 1999, 19000, "https://www.youtube.com/watch?v=SUXWAEX2jlg");
    this->add_s("Black Swan", "horror", 2010, 94000, "https://www.youtube.com/watch?v=5jaI1XOB-bs");
    this->add_s("Dune 2", "science fiction", 2024, 422000, "https://www.youtube.com/watch?v=Way9Dexny3w");
    this->add_s("No Country for Old Men", "thriller", 2007, 27000, "https://www.youtube.com/watch?v=38A__WT3-o0");
    this->add_s("The Good, the Bad and the Ugly", "western", 1966, 10000, "https://www.youtube.com/watch?v=WCN5JJY_wiA");
    this->add_s("Blade Runner 2049", "science fiction", 2017, 262000, "https://www.youtube.com/watch?v=gCcx85zbxz4");
    this->add_s("Predator", "science fiction", 1987, 10000, "https://www.youtube.com/watch?v=X2hBYGwKh3I");
    this->add_s("Terminator", "science fiction", 1984, 16000, "https://www.youtube.com/watch?v=k64P4l2Wmeg");

}

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

bool Services::update_s(std::string title, int year, std::string newtitle, std::string newgenre,
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
    for ( const auto& ind : *v)
    {
        Movie mov = ind;
        if ( mov.getGenre() == genre || genre.empty())
            res.push_back(mov);
    }
    return res;
}

bool Services::add_watch_s(std::string title, std::string genre, int year, int likes, std::string trailer) {
    this->repo.add_to_watch(title, genre, year, likes, trailer);
    return true;
}

//void Services::write_to_json(std::string typelist, std::string filename) {
//    std::vector<Movie>* v;
//    if (typelist == "movielist")
//        v = this->getList_s();
//    else if (typelist == "watchlist")
//        v = this->getwatchlist_s();
//    else
//        return;
//
//    nlohmann::json jarr = nlohmann::json::array();
//    for (const auto& i : *v){
//        nlohmann::json obj;
//        Movie mov = i;
//        obj["title"] = mov.getTitle();
//        obj["genre"] = mov.getGenre();
//        obj["year"] = mov.getYear();
//        obj["likes"] = mov.getLikes();
//        obj["trailer"] = mov.getTrailer();
//        jarr.push_back(obj);
//    }
//
//    if (typelist == "movielist") {
//        std::ofstream out("..\\Services\\JSONsaves\\"+filename);
//        out << jarr;
//        out.close();
//    }
//    else{
//        std::ofstream out("..\\Services\\JSONsaves\\"+filename);
//        out << jarr;
//        out.close();
//    }
//}

//void Services::json_add_handler(std::string typelist, Movie mov) {
//    if (typelist == "movielist"){
//        this->add_s(mov.getTitle(), mov.getGenre(), mov.getYear(), mov.getLikes(),
//                    mov.getTrailer());
//    }
//    else if (typelist == "watchlist"){
//        this->add_watch_s(mov.getTitle(), mov.getGenre(), mov.getYear(), mov.getLikes(),
//                          mov.getTrailer());
//    }
//}

//void Services::read_from_json(std::string typelist, std::string filename) {
//
//        nlohmann::json jarr = nlohmann::json::array();
//        std::ifstream in("..\\Services\\JSONsaves\\"+filename);
//        jarr = nlohmann::json::parse(in);
//        in.close();
//        for (auto i = jarr.begin(); i < jarr.end(); i++){
//                auto mov = new Movie(i->at("title").get<std::string>(), i->at("genre").get<std::string>(),
//                                       i->at("year").get<int>(), i->at("likes").get<int>(),
//                                       i->at("trailer").get<std::string>());
//                this->json_add_handler(typelist, *mov);
//        }
//}

void Services::set_output_type(std::string type) {
    this->outputfileext = type;
    this->repo.set_output_type(type);
}

std::string Services::get_outputfile_ext() {
    return this->outputfileext;
}

std::string Services::get_movies_filename_s() {
    return this->repo.get_movies_filename();
}

void Services::write_to_file_s(std::vector<Movie>* v, std::string filename){
    this->repo.write_to_file(v, filename);
}

void Services::read_from_file_s(std::vector<Movie>* v,std::string filename) {
    this->repo.read_from_file(v, filename);
}
