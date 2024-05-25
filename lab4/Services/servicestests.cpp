//
// Created by zelu on 22.03.2024.
//

#include "servicestests.h"
#include "services.h"
#include <assert.h>
#include <iostream>


void services_tests(){
    Repository repo{"testmovielist.json"};
    Services serv{repo};
    serv.add_s("Scufita rosie", "comedie",2024, 69, "https://www.youtube.com/cox");
    assert(serv.add_s("Scufita rosie", "testgenre", 2024, 420, "https://www.youtube.com/") == false);
    //std::cout << "finished adding elem in services \n";
    std::vector<Movie>* v;
    v = serv.getList_s();
    //std::cout << "length of vector: " << v->length() << "\n";
    assert(v->size() == 1);
    assert(v->at(v->size()-1).getTitle() == "Scufita rosie");
    serv.update_s("Scufita rosie", 2024, "Scufita Rosie", "horror", 2000, 1337, "https://www.youtube.com/scufita");
    assert(v->at(v->size()-1).getTitle() == "Scufita Rosie");
    assert(v->at(v->size()-1).getGenre() == "horror");
    assert(v->at(v->size()-1).getYear() == 2000);
    assert(v->at(v->size()-1).getLikes() == 1337);
    assert(v->at(v->size()-1).getTrailer() == "https://www.youtube.com/scufita");
    assert(v->size() == 1);
    assert(serv.update_s("Scufita rosie", 2000, "Scufita Rosie", "comedie", 1999, 420, "https://somesite.com/") == false);
    assert(serv.remove_s("Scufita rosie", 2000) == false);
    assert(serv.update_s("Nu exista", 2000, "Nu exista2", "idkgenre", 1999, 555, "https://www.youtube.com/") == false);


    std::vector<Movie> watchlist;
    assert(watchlist.size() == serv.getwatchlist_s()->size());

    serv.add_watch_s("Scufita Rosie", "horror", 2000, 1337, "https://www.youtube.com/scufita");
    assert(watchlist.size() != serv.getwatchlist_s()->size());
    assert(serv.getwatchlist_s()->size() == 1);
    assert(serv.getwatchlist_s()->at(0).getTitle() == "Scufita Rosie");

    assert(serv.add_s("Test", "testgenre", 1999, 444, "http://somesite.com/") == false);


    serv.remove_s("Scufita Rosie", 2000);
    assert(v->size() == 0);


    serv.add_s("test1", "scifi", 1998, 564, "https://www.youtube.com/");
    serv.add_s("test2", "scifi", 1999, 574, "https://www.youtube.com/");

    auto movbygenre = serv.movies_by_genre("scifi");
    assert(movbygenre.size() == 2);
    assert(movbygenre.at(0).getTitle() == "test1");
    assert(movbygenre.at(0).getGenre() == "scifi");
    assert(movbygenre.at(1).getTitle() == "test2");
    assert(movbygenre.at(1).getGenre() == "scifi");
}