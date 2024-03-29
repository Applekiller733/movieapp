//
// Created by zelu on 22.03.2024.
//

#include "servicestests.h"
#include "services.h"
#include <assert.h>
#include <iostream>


void services_test_quantity(){
    Services serv;
    DynamicVector* v;
    v = serv.getList_s();
    int cnt = 0;
    for (int i = 0; i < 40000; i++)
    {
        for (int j = 0; j < 5; j++) {
            serv.add_s(std::to_string(cnt), "test", cnt, 99, "test.com");
            cnt++;
        }
    }
    assert (v->length() == 200000);
    cnt = 0;
    for (int i = 0; i < 40000; i++)
        for (int j = 0; j < 2; j++) {
            serv.remove_s(std::to_string(cnt), cnt);
            cnt++;
        }
    assert (v->length() == 120000);
}

void services_tests(){
    Services serv;
    serv.add_s("Scufita rosie", "comedie",2024, 69, "https://www.youtube.com/cox");
    //std::cout << "finished adding elem in services \n";
    DynamicVector* v;
    v = serv.getList_s();
    //std::cout << "length of vector: " << v->length() << "\n";
    assert(v->length() == 1);
    assert(v->getElem(v->length()-1).getTitle() == "Scufita rosie");
    serv.remove_s("Scufita rosie", 2024);
    assert(v->length() == 0);
}