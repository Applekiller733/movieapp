//
// Created by ANDREI on 08-May-24.
//

#include "GUI.h"
#include "../Services/services.h"
#include <QApplication>
#include <QWidget>
#include <qlayout.h>
#include <qlabel.h>

GUI::GUI() {
    this->serv.initialize_repo();

    this->buildGUI();
    this->populatelist();
    QObject::connect(this->addbutton, &QPushButton::clicked, this, &GUI::addbuttonhandler);
    QObject::connect(this->deletebutton, &QPushButton::clicked, this, &GUI::deletebuttonhandler);
}

void GUI::buildGUI() {
    QGridLayout *mainLayout = new QGridLayout{this};
    this->movielistwidget = new QListWidget{};
    mainLayout->addWidget(this->movielistwidget, 0, 0);

    QGridLayout *righteditlayout = new QGridLayout{};

    QLabel* titlelabel = new QLabel{"Title"};
    this->titleline = new QLineEdit{};

    QLabel* genrelabel = new QLabel{"Genre"};
    this->genreline = new QLineEdit{};

    QLabel* yearlabel = new QLabel{"Year"};
    this->yearline = new QLineEdit{};

    QLabel* likeslabel = new QLabel{"Likes"};
    this->likesline = new QLineEdit{};

    QLabel* trailerlabel = new QLabel{"Trailer"};
    this->trailerline = new QLineEdit{};

    righteditlayout->addWidget(titlelabel, 0, 0);
    righteditlayout->addWidget(this->titleline, 0, 1);
    righteditlayout->addWidget(genrelabel, 1, 0);
    righteditlayout->addWidget(this->genreline, 1, 1);
    righteditlayout->addWidget(yearlabel, 2, 0);
    righteditlayout->addWidget(this->yearline, 2, 1);
    righteditlayout->addWidget(likeslabel, 3, 0);
    righteditlayout->addWidget(this->likesline, 3, 1);
    righteditlayout->addWidget(trailerlabel, 4, 0);
    righteditlayout->addWidget(this->trailerline, 4, 1);

    mainLayout->addLayout(righteditlayout, 0, 1);

    QGridLayout* bottombuttonslayout = new QGridLayout{};
    this->addbutton = new QPushButton{"Add"};
    this->deletebutton = new QPushButton{"Delete"};

    bottombuttonslayout->addWidget(this->addbutton, 0, 0);
    bottombuttonslayout->addWidget(this->deletebutton, 0, 1);

    mainLayout->addLayout(bottombuttonslayout, 1, 0, 1, 2);

}

void GUI::populatelist() {
    this->movielistwidget->clear();
    for(auto mov : *this->serv.getList_s()){
        this->movielistwidget->addItem(QString::fromStdString(mov.getTitle() + ", " + std::to_string(mov.getYear())));
    }
}

void GUI::addbuttonhandler() {
    QString title = this->titleline->text();
    QString genre = this->genreline->text();
    QString year = this->yearline->text();
    QString likes = this->likesline->text();
    QString trailer = this->trailerline->text();
    this->serv.add_s(title.toStdString(), genre.toStdString(), year.toInt(), likes.toInt(), trailer.toStdString());
    this->populatelist();
}

void GUI::deletebuttonhandler() {
    QString title = this->titleline->text();
    QString year = this->yearline->text();
    this->serv.remove_s(title.toStdString(), year.toInt());
    this->populatelist();
}