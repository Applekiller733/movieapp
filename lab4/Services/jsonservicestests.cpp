//
// Created by zelu on 16.04.2024.
//

#include "jsonservicestests.h"
#include "services.h"
#include <assert.h>


void jsonservicestests(){
    Services serv;

    serv.add_s("test1", "scifi", 1999, 555, "https://www.youtube.com/");
    serv.add_s("test2", "scifi", 1999, 777, "https://www.youtube.com/");

    serv.write_to_json("movielist", "testmovielist.json");
    assert(serv.getList_s()->size() == 2);
    assert(serv.getwatchlist_s()->size() == 0);

    serv.add_watch_s("test1", "scifi", 1999, 555, "https://www.youtube.com/");
    assert(serv.getwatchlist_s()->size() == 1);

    serv.write_to_json("watchlist", "testwatchlist.json");

    serv.write_to_json("test", "testwatchlist.json");

    serv.write_to_json("test", "testmovielist.json");

    serv.read_from_json("test", "testmovielist.json");

    Services serv2;

    serv2.read_from_json("movielist", "testmovielist.json");
    assert(serv2.getList_s()->size() == 2);

    serv2.read_from_json("watchlist", "testwatchlist.json");
    assert(serv2.getwatchlist_s()->size() == 1);

}