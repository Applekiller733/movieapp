//
// Created by ANDREI on 08-May-24.
//

#include "GUI.h"
#include "../Services/services.h"
#include <QApplication>
#include <QWidget>
#include <qlayout.h>
#include <qlabel.h>
#include <qerrormessage.h>

GUI::GUI(Services& serv) : serv{serv} {

    this->serv.read_from_file_s(this->serv.getList_s(), this->serv.get_movies_filename_s());
//    this->serv.populate_repo();  remove when file reading complete
    this->tab = new QTabWidget{this};
    this->buildGUI();

}

void GUI::buildGUI() {
    this->adminpage = new Admin(this->serv);
    tab->addTab(this->adminpage, "Admin");

    this->userpage = new User(this->serv);
    tab->addTab(this->userpage, "User");

    tab->setCurrentWidget(this->adminpage);

    auto mainLayout = new QVBoxLayout{this};
    mainLayout->addWidget(this->tab);
    this->setLayout(mainLayout);

}

Admin::Admin(Services &serv) : serv{serv}{

    this->error = new QErrorMessage;

    this->buildAdmin();
}

void Admin::buildAdmin() {

    auto mainLayout = new QGridLayout{};
    this->movielistwidget = new QListWidget{};
    mainLayout->addWidget(this->movielistwidget, 0, 0);
    this->movielistwidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->movielistwidget->setMinimumSize(600, 250);

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

    //setting size for line edits
    this->titleline->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->titleline->setMinimumSize(200, 1);

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
    this->updatebutton = new QPushButton{"Update"};

    bottombuttonslayout->addWidget(this->addbutton, 0, 0);
    bottombuttonslayout->addWidget(this->deletebutton, 0, 2);
    bottombuttonslayout->addWidget(this->updatebutton, 0, 1);

    mainLayout->addLayout(bottombuttonslayout, 1, 0, 1, 2);

    QObject::connect(this->addbutton, &QPushButton::clicked, this, &Admin::addbuttonhandler);
    QObject::connect(this->deletebutton, &QPushButton::clicked, this, &Admin::deletebuttonhandler);
    QObject::connect(this->updatebutton, &QPushButton::clicked, this, &Admin::updatebuttonhandler);

    QObject::connect(this->movielistwidget, &QListWidget::itemClicked, this, &Admin::itemclickedhandler);

    this->setLayout(mainLayout);
    this->populatelist();

}

void Admin::itemclickedhandler(QListWidgetItem* clickeditem) {
    auto index = this->movielistwidget->indexFromItem(clickeditem).row();
    auto mov = this->serv.getList_s()->at(index);
    this->titleline->setText(QString::fromStdString(mov.getTitle()));
    this->genreline->setText(QString::fromStdString(mov.getGenre()));
    this->yearline->setText(QString::fromStdString(std::to_string(mov.getYear())));
    this->likesline->setText(QString::fromStdString(std::to_string(mov.getLikes())));
    this->trailerline->setText(QString::fromStdString(mov.getTrailer()));
}

void Admin::populatelist() {
    this->movielistwidget->clear();
    for(auto mov : *this->serv.getList_s()){
        this->movielistwidget->addItem(QString::fromStdString(mov.getTitle() + ", "
        + (mov.getGenre()) + ", " + std::to_string(mov.getYear()) + ", " + std::to_string(mov.getLikes())
        + ", " + mov.getTrailer()));
    }
}

void Admin::addbuttonhandler() {
    QString title = this->titleline->text();
    QString genre = this->genreline->text();
    QString year = this->yearline->text();
    QString likes = this->likesline->text();
    QString trailer = this->trailerline->text();
    if (!this->serv.add_s(title.toStdString(), genre.toStdString(),
                         year.toInt(), likes.toInt(), trailer.toStdString()))
    {
        this->error->showMessage("Invalid object to add!");
    }
        this->populatelist();
}

void Admin::updatebuttonhandler() {

}

void Admin::deletebuttonhandler() {
    QString title = this->titleline->text();
    QString year = this->yearline->text();
    if (!this->serv.remove_s(title.toStdString(), year.toInt())){
        this->error->showMessage("Invalid object to delete!");
    }
    this->populatelist();
}

User::User(Services &serv) : serv{serv}{

    this->error = new QErrorMessage;

    this->buildUser();
}

void User::buildUser() {
    mainLayout = new QGridLayout{};

    leftLayout = new QGridLayout{};

    QLabel* searchlabel = new QLabel{"Search by genre:"};
    this->searchline = new QLineEdit{};
    this->searchbutton = new QPushButton{"Search"};

    leftLayout->addWidget(searchlabel, 2, 2);
    leftLayout->addWidget(this->searchline, 2, 3);
    leftLayout->addWidget(this->searchbutton, 2, 4);

    mainLayout->addLayout(leftLayout, 0, 0);



    auto rightLayout = new QVBoxLayout{};

    this->watchlistwidget = new QListWidget{};
    rightLayout->addWidget(this->watchlistwidget);

    this->displaybutton = new QPushButton{"Display list"};
    this->deletebutton = new QPushButton{"Delete element"};
    this->savebutton = new QPushButton{"Save watchlist"};

    rightLayout->addWidget(this->displaybutton);
    rightLayout->addWidget(this->deletebutton);
    rightLayout->addWidget(this->savebutton);

    mainLayout->addLayout(rightLayout, 0, 1);

    this->setLayout(mainLayout);
}

void User::searchhandler() {
    std::string genre = this->searchline->text().toStdString();
}

void User::next_movie() {

}