//
// Created by ANDREI on 21-Mar-24.
//

#include "repository.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../nlohmann/json.hpp"
#include <fstream>
//repo exception
RepositoryException::RepositoryException(const std::string message) {
    this->message = message;
}

std::string RepositoryException::getMessage() const {
    return this->message;
}


//Repository

Repository::Repository(std::string filename) : moviesfilename{filename} {

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
        auto& mov = this->v[i];
        if (mov.getTitle() == title && mov.getYear() == year)
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
    this->write_to_file(this->getList(), this->moviesfilename);
}

void Repository::remove_repo(std::string title, int year) {
    int index = this->findIndex(title, year);
    this->v.erase(v.begin()+index);
    this->write_to_file(this->getList(), this->moviesfilename);
}

void Repository::update_repo(std::string title, int year, std::string newtitle, std::string newgenre, int newyear,
                             int newlikes, std::string newtrailer) {
    int index = this->findIndex(title, year);
    Movie newmov(newtitle, newgenre, newyear, newlikes, newtrailer);
    this->v[index] = newmov;
    this->write_to_file(this->getList(), this->moviesfilename);
}

void Repository::add_to_watch(std::string title, std::string genre, int year, int likes, std::string trailer) {
    Movie newmov(title, genre, year, likes, trailer);
    this->watchlist.push_back(newmov);
    //todo add file save
}

void Repository::set_output_type(std::string type) {
    this->outputfileext = type;
}

std::string Repository::get_outputfile_ext() {
    return this->outputfileext;
}

//void Repository::write_to_html(std::string filename) {
//    std::ofstream fout("..\\Services\\HTMLsaves\\" + filename + this->outputfileext);
//    if (!fout.is_open())
//        throw RepositoryException("File could not be opened!\n");
//
//    fout << "<!DOCTYPE HTML>\n";
//    fout << "<html>\n";
//    fout << "<head>\n"
//            "\t<title>Movie Watch List</title>"
//            "</head>\n";
//    fout << "<body>\n"
//            "<table border = \"1\">\n";
//    for ( auto& mov : this->watchlist ){
//        fout << "\t<tr>\n";
//        fout << "\t\t<td>" + mov.getTitle() + "</td>\n";
//        fout << "\t\t<td>" + mov.getGenre() + "</td>\n";
//        fout << "\t\t<td>" + std::to_string(mov.getYear()) + "</td>\n";
//        fout << "\t\t<td>" + std::to_string(mov.getLikes()) + "</td>\n";
//        fout << "\t\t<td><a href =" + mov.getTrailer() + ">Trailer</a></td>\n";
//        fout << "\t</tr>\n";
//    }
//    fout << "</table>\n"
//            "</body>\n"
//            "</html>\n";
//}

//void Repository::write_to_csv(std::string filename) {
//    std::ofstream fout("..\\Services\\CSVsaves\\" + filename + this->outputfileext);
//    if (!fout.is_open())
//        throw RepositoryException("File could not be opened!\n");
//    for ( auto& mov : this->watchlist){
//        fout << mov.getTitle() << "," << mov.getGenre() << "," << mov.getYear() << ","
//             << mov.getLikes() << "," << mov.getTrailer() << "\n";
//    }
//    fout.close();
//}

std::string Repository::get_movies_filename() {
    return this->moviesfilename;
}

void Repository::write_to_file(std::vector<Movie>* v, std::string filename) {

    nlohmann::json jarr = nlohmann::json::array();
    for (const auto &i: *v) {
        nlohmann::json obj;
        Movie mov = i;
        obj["title"] = mov.getTitle();
        obj["genre"] = mov.getGenre();
        obj["year"] = mov.getYear();
        obj["likes"] = mov.getLikes();
        obj["trailer"] = mov.getTrailer();
        jarr.push_back(obj);
    }

    std::ofstream out("..\\Services\\JSONsaves\\" + filename);
    out << jarr;
    out.close();
}

void Repository::read_from_file(std::vector<Movie> *v, std::string filename) {
    nlohmann::json jarr = nlohmann::json::array();
    std::ifstream in("..\\Services\\JSONsaves\\"+filename);
    jarr = nlohmann::json::parse(in);
    in.close();
    v->clear();
    for (auto i = jarr.begin(); i < jarr.end(); i++){
        auto mov = new Movie(i->at("title").get<std::string>(), i->at("genre").get<std::string>(),
                             i->at("year").get<int>(), i->at("likes").get<int>(),
                             i->at("trailer").get<std::string>());
        v->push_back(*mov);
    }
}

CSVRepository::CSVRepository(std::string filename) : Repository(filename){}

void CSVRepository::write_to_file(std::vector<Movie>* v, std::string filename) {
    std::ofstream fout("..\\Services\\CSVsaves\\" + filename + this->get_outputfile_ext());
    if (!fout.is_open())
        throw RepositoryException("File could not be opened!\n");
    for ( auto& mov : *v){
        fout << mov.getTitle() << "," << mov.getGenre() << "," << mov.getYear() << ","
             << mov.getLikes() << "," << mov.getTrailer() << "\n";
    }
    fout.close();
}

void CSVRepository::read_from_file(std::vector<Movie> *v, std::string filename) {
    std::ifstream fin("..\\Services\\CSVsaves\\" + filename + this->get_outputfile_ext());
    if ( !fin.is_open())
        throw RepositoryException("File could not be opened!\n");
    std::string line;
    std::string delim = ",";
    while(std::getline(fin, line)){
        std::string title = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + delim.length());
        std::string genre = line.substr(0, line.find(delim));
        line.erase(0, line.find(delim) + delim.length());
        int year = std::stoi(line.substr(0, line.find(delim)));
        line.erase(0, line.find(delim) + delim.length());
        //std::cout << "Got here\n";
        int likes = std::stoi(line.substr(0, line.find(delim)));
        line.erase(0, line.find(delim) + delim.length());
        std::string trailer = line;
        //todo check if correct
        this->add_repo(title, genre, year, likes, trailer);
    }
}

HTMLRepository::HTMLRepository(std::string filename) : Repository(filename){}

void HTMLRepository::write_to_file( std::vector<Movie>* v, std::string filename) {
    std::ofstream fout("..\\Services\\HTMLsaves\\" + filename + this->get_outputfile_ext());
    if (!fout.is_open())
        throw RepositoryException("File could not be opened!\n");

    fout << "<!DOCTYPE HTML>\n";
    fout << "<html>\n";
    fout << "<head>\n"
            "\t<title>Movie Watch List</title>"
            "</head>\n";
    fout << "<body>\n"
            "<table border = \"1\">\n";
    for ( auto& mov : *v ){
        fout << "\t<tr>\n";
        fout << "\t\t<td>" + mov.getTitle() + "</td>\n";
        fout << "\t\t<td>" + mov.getGenre() + "</td>\n";
        fout << "\t\t<td>" + std::to_string(mov.getYear()) + "</td>\n";
        fout << "\t\t<td>" + std::to_string(mov.getLikes()) + "</td>\n";
        fout << "\t\t<td><a href =" + mov.getTrailer() + ">Trailer</a></td>\n";
        fout << "\t</tr>\n";
    }
    fout << "</table>\n"
            "</body>\n"
            "</html>\n";
}
