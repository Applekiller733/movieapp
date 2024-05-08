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

#include "../Services/services.h"

class GUI : public QWidget{
private:
     Services serv;

     QListWidget* movielistwidget;

     QLineEdit* titleline;
     QLineEdit* genreline;
     QLineEdit* yearline;
     QLineEdit* likesline;
     QLineEdit* trailerline;

     QPushButton* addbutton;
     QPushButton* deletebutton;
     //QPushButton* updatebutton;


     void populatelist();
     void buildGUI();

public:
    GUI();

    void addbuttonhandler();
    void deletebuttonhandler();

};

#endif //LAB4_GUI_H
