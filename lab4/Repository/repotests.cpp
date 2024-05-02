//
// Created by ANDREI on 21-Mar-24.
//

#include "repotests.h"
#include <assert.h>
#include <iostream>

void short_test(){
    std::cout << "entered tests \n";
    DynamicVector v(0);
    std::cout << "tests: successfully created vector\n";
    Movie mov1("Scufita Rosie", "comedie", 2024, 69, "https://cox.ro");
    std::cout << "tests: successfully created movie\n";
    v.add(mov1);
    std::cout << "tests: finished adding\n";
    assert(v.length() == 1);
    v.remove("Scufita Rosie", 2024);
    std::cout << "tests: finished removing \n";
}