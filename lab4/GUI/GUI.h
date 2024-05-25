//
// Created by ANDREI on 08-May-24.
//

#ifndef LAB4_GUI_H
#define LAB4_GUI_H
#include <QApplication>
#include <QWidget>
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qerrormessage.h>
#include <qstackedwidget.h>

#include "../Services/services.h"

class Admin : public QWidget{
private:
    Services& serv;

    QListWidget* movielistwidget;

    QLineEdit* titleline;
    QLineEdit* genreline;
    QLineEdit* yearline;
    QLineEdit* likesline;
    QLineEdit* trailerline;

    QPushButton* addbutton;
    QPushButton* deletebutton;
    QPushButton* updatebutton;

    QErrorMessage* error;

public:
    Admin(Services& serv);
    void buildAdmin();
    void populatelist();

    void addbuttonhandler();
    void updatebuttonhandler();
    void deletebuttonhandler();
    void itemclickedhandler(QListWidgetItem* clickeditem);
};

class User : public QWidget{
private:

    int currmovind = 0; //todo add cycling through the movies
    Services& serv;

    QGridLayout* mainLayout;
    QGridLayout* leftLayout;

    QLineEdit* searchline;
    QPushButton* searchbutton;

    QListWidget* watchlistwidget;

    QPushButton* deletebutton;
    QPushButton* displaybutton;
    QPushButton* savebutton;

    QErrorMessage* error;
public:
    User(Services& serv);
    void buildUser();

    void searchhandler();
    void next_movie();
};

class GUI : public QWidget{
private:
     Services& serv;

     QTabWidget* tab;

     //add another class for admin/user?
     Admin* adminpage;
     User* userpage;

     void buildGUI();

public:
    GUI(Services& serv);

};

#endif //LAB4_GUI_H
