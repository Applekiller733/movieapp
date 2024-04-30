#include <iostream>
#include "UI/ui.h"
#include "Repository/repotests.h"
#include "Services/servicestests.h"
#include "Domain/jsondomaintest.h"
#include "Services/jsonservicestests.h"

int main() {
    short_test();
    services_tests();
    //services_test_quantity();
    test();
    jsontest2();
    jsonservicestests();
    //todo make extensive tests
    //maybe add a way to save watchlist and vector in JSON - DONE

    UI ui;
    ui.start();
}
