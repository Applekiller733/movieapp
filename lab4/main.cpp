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
    //test();
    //jsontest2();
    jsonservicestests();
    //debg_write();
    // fix filepaths - DONE
    // fix link opening (use QT?) - DONE (windows only fix)

    //TODO LIST:
    //add exception classes, validators
    //add CSV file saving
    //add HTML file saving
    //open CSV files in Excel/HTML files in browser
    //create UML diagram of program

    UI ui;
    ui.start();
}
