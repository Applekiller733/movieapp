//
// Created by ANDREI on 21-Mar-24.
//

#include "repotests.h"
#include <assert.h>
#include <iostream>

void short_test(){
    //std::cout << "entered tests \n";
    Repository repo;
    //std::cout << "tests: successfully created vector\n";
    Movie mov1("Scufita Rosie", "comedie", 2024, 69, "https://cox.ro");
    //std::cout << "tests: successfully created movie\n";
    repo.add_repo("Scufita Rosie", "comedie", 2024, 69, "https://cox.ro"); //check for unexpected memory deletion
    //std::cout <<"mov1 title: "<<mov1.getTitle() << " genre: " << mov1.getGenre() << " trailer "<< mov1.getTrailer()<<"\n";
    Movie mov2("Lupu albastru", "horror", 2077, 1337, "https://lupulameaiiplacedemata.ro");
    repo.add_repo("Lupu albastru", "horror", 2077, 1337, "https://lupulameaiiplacedemata.ro");
    //std::cout << "tests: finished adding\n";
    assert(repo.getList()->length() == 2);
    //getelem / getlist tests
    Movie elem1;
    elem1 = repo.getList()->getElem(1);
    assert(elem1.getTitle() == "Lupu albastru");
    DynamicVector* newv;
    newv = repo.getList();
    //std::cout << "Debug length: " << newv->length() <<"\n";
    assert(newv->length() == 2);
    assert(newv->getElem(1).getTitle() == "Lupu albastru");

    DynamicVector tryv;
    for (int ind = 0; ind < newv->length(); ind++){
        Movie mov(newv->getElem(ind).getTitle(), newv->getElem(ind).getGenre(),
                  newv->getElem(ind).getYear(), newv->getElem(ind).getLikes(),
                  newv->getElem(ind).getTrailer());
        tryv.add(mov);
    }
    assert(tryv.length() == 2);
    assert(tryv.getElem(1).getTitle() == "Lupu albastru");

    repo.remove_repo("Scufita Rosie", 2024);
    assert(repo.getList()->length() == 1);
    repo.remove_repo("Lupu albastru", 2077);
    assert(repo.getList()->length() == 0);
//    assert(v.length() == 0);
    //std::cout << "tests: finished removing \n";
    //delete mov1;

    //std::cout << "Tests finished \n";
}