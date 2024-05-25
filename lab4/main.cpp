#include <iostream>
#include "UI/ui.h"
#include "Repository/repotests.h"
#include "Services/servicestests.h"
#include "Domain/jsondomaintest.h"
#include "Services/jsonservicestests.h"
#include "Repository/repository.h"
#include "Services/services.h"
#include "GUI/GUI.h"

#include <QtWidgets/QApplication>
#include <QtWebView/QtWebView>

int main(int argc, char* argv[]) {
    short_test();
    services_tests();
    //services_test_quantity();
    //test();
    //jsontest2();
    //jsonservicestests();
    //debg_write();

//    TODO LIST:
//     fix filepaths - DONE
//     fix link opening (use QT?) - DONE (windows only fix)
//     add exception classes, validators - DONE
//     add CSV file saving - DONE
//     add HTML file saving - DONE
//     open CSV files in Excel/HTML files in browser - DONE
//     create UML diagram of program - DONE
//     migrate all file writing/reading to repository - DONE
//     finish html/csv file reading for repository - 80%ish complete - still require HTML file reading
//     finish GUI
//     refactor Repository and add polymorphism - DONE
//     refactor console UI?
//     remake tests
//     switch to Qt JSON instead of nlohmann


//    UI ui;
//    ui.start();

    CSVRepository repo{"movielist.csv"};
    Services serv{repo};
    //QtWebView::initialize(); required for webview
    QApplication app(argc, argv);
    app.setApplicationName("Movieapp");
    app.setStyle("fusion");
    GUI gui{serv};
    gui.show();
    return app.exec();

}
