#include <iostream>
#include "UI/ui.h"
#include "Repository/repotests.h"
#include "Services/servicestests.h"
#include "Domain/jsondomaintest.h"
#include "Services/jsonservicestests.h"
#include "GUI/GUI.h"

#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {
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

//    UI ui;
//    ui.start();

    QApplication app(argc, argv);
    app.setApplicationName("Movieapp");
    GUI gui;
    gui.show();
    return app.exec();

}
