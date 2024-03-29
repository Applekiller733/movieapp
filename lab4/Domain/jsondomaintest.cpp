//
// Created by zelu on 28.03.2024.
//

#include "jsondomaintest.h"
#include "domain.h"
#include "../nlohmann/json.hpp"
#include <fstream>
#include <iostream>


//void test() {
//    Movie mov("testtitle", "testgenre", 2024, 69, "https://www.youtube.com/test");
//    nlohmann::json j;
//    j["title"]=mov.getTitle();
//    j["genre"]=mov.getGenre();
//    j["year"]=mov.getYear();
//    j["likes"]=mov.getLikes();
//    j["trailer"]=mov.getTrailer();
//    //std::cout << j;
//    std::ofstream out("jsontest.json");
//    if (!out) {
//        std::cerr << "Error writing to file." << std::endl;
//        // Handle the error, such as returning or throwing an exception
//    }
//    out << j;
//    out.close();
//}

void test() {
    Movie mov("testtitle", "testgenre", 2024, 69, "https://www.youtube.com/test");
    nlohmann::json j;
    j["title"] = mov.getTitle();
    j["genre"] = mov.getGenre();
    j["year"] = mov.getYear();
    j["likes"] = mov.getLikes();
    j["trailer"] = mov.getTrailer();

    std::ofstream out("/home/zelu/CLionProjects/OOP/lab4/Domain/jsontest.json");
    try {
        if (!out) {
            throw std::runtime_error("Error opening file for writing.");
        }
        out << j;
        out.flush();
        out.close();
    } catch (const std::exception& e) {
        std::cerr << "Error writing to file: " << e.what() << std::endl;
    }

    Movie newmov;
    std::ifstream in("/home/zelu/CLionProjects/OOP/lab4/Domain/jsontest.json");
    nlohmann::json jin;
    in >> jin;
    newmov.setTitle(j["title"].template get<std::string>());
    newmov.setGenre(j["genre"].template get<std::string>());
    newmov.setTrailer(j["trailer"].template get<std::string>());
    newmov.setYear(j["year"].template get<int>());
    newmov.setLikes(j["likes"].template get<int>());

    std::cout << "Title: " << newmov.getTitle() << "\n";

}

void jsontest2(){
    auto elems = new Movie[2];
    elems[0].setTitle("Dune");
    elems[0].setGenre("science fiction");
    elems[0].setYear(2021);
    elems[0].setLikes(679000);
    elems[0].setTrailer("https://www.youtube.com/watch?v=n9xhJrPXop4");

    elems[1].setTitle("Dune 2");
    elems[1].setGenre("science fiction");
    elems[1].setYear(2024);
    elems[1].setLikes(700000);
    elems[1].setTrailer("https://www.youtube.com/watch?v=n9xhJrPXop4");

    nlohmann::json jsonarr = nlohmann::json::array();
    for (int i = 0; i < 2; i++){
        nlohmann::json obj;
        obj["title"] = elems[i].getTitle();
        obj["genre"] = elems[i].getGenre();
        obj["year"] = elems[i].getYear();
        obj["likes"] = elems[i].getLikes();
        obj["trailer"] = elems[i].getTrailer();
        jsonarr.push_back(obj);
    }

    std::ofstream out("/home/zelu/CLionProjects/OOP/lab4/Domain/jsontest.json");
    out << jsonarr;
    out.close();


    std::ifstream in("/home/zelu/CLionProjects/OOP/lab4/Domain/jsontest.json");
    nlohmann::json jin = nlohmann::json::parse(in);
    in.close();
    auto newelems = new Movie[2];

    for (int i = 0; i < 2; i++){
        newelems[i].setTitle(jin[i]["title"].template get<std::string>());
        newelems[i].setGenre(jin[i]["genre"].template get<std::string>());
        newelems[i].setTrailer(jin[i]["trailer"].template get<std::string>());
        newelems[i].setYear(jin[i]["year"].template get<int>());
        newelems[i].setLikes(jin[i]["likes"].template get<int>());
    }
    //todo implement for main project
    //it works!

//    for (int i = 0; i < 2; i++){
//        std::cout << "Title: " << newelems[i].getTitle() << "\n" <<
//        "Genre: " << newelems[i].getGenre() << "\n" <<
//        "Year: " << newelems[i].getYear() << "\n" <<
//        "Likes: " << newelems[i].getLikes() << "\n" <<
//        "Trailer: " << newelems[i].getTrailer() << "\n\n";
//    }


    delete[] elems;
    delete[] newelems;
}

void testloadjson(){
    auto elems = new Movie[2];
    nlohmann::json j;

    delete[] elems;
}