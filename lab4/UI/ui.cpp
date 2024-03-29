//
// Created by ANDREI on 20-Mar-24.
//

//#include <string>
#include <string.h>
#include <iostream>

#include <string>
#include <cctype>
#include <limits>
#include <stdlib.h>
#include "ui.h"




UI::UI() {

}

//int UI::wordcnt(const char *sentence){
//    if (sentence == NULL)
//        return -1;
//    int cnt = 0;
//    bool inspace = true;
//    while(*sentence != '\0'){
//        if (std::isspace(*sentence)){
//            inspace = true;
//        }
//        else{
//            if (inspace == true)
//                cnt++;
//            inspace = false;
//        }
//        ++sentence;
//    }
//    return cnt;
//}

void UI::initialize_repo() {
    /*
     * Initializes movie list with some movie entries*/
    this->serv.add_s("Dune", "science fiction", 2021, 679000, "https://www.youtube.com/watch?v=n9xhJrPXop4");
    this->serv.add_s("Whiplash", "drama", 2015, 65000, "https://www.youtube.com/watch?v=7d_jQycdQGo");
    this->serv.add_s("Fight Club", "thriller", 1999, 19000, "https://www.youtube.com/watch?v=SUXWAEX2jlg");
    this->serv.add_s("Black Swan", "horror", 2010, 94000, "https://www.youtube.com/watch?v=5jaI1XOB-bs");
    this->serv.add_s("Dune 2", "science fiction", 2024, 422000, "https://www.youtube.com/watch?v=Way9Dexny3w");
    this->serv.add_s("No Country for Old Men", "thriller", 2007, 27000, "https://www.youtube.com/watch?v=38A__WT3-o0");
    this->serv.add_s("The Good, the Bad and the Ugly", "western", 1966, 10000, "https://www.youtube.com/watch?v=WCN5JJY_wiA");
    this->serv.add_s("Blade Runner 2049", "science fiction", 2017, 262000, "https://www.youtube.com/watch?v=gCcx85zbxz4");
    this->serv.add_s("Predator", "science fiction", 1987, 10000, "https://www.youtube.com/watch?v=X2hBYGwKh3I");
    this->serv.add_s("Terminator", "science fiction", 1984, 16000, "https://www.youtube.com/watch?v=k64P4l2Wmeg");
}

void UI::start() {
    /*
     * Asks if operator wishes to load movie/watch lists from JSON files and then proceeds
     * to login menu*/
    std::string inp;

    std::cout << "Do you wish to load movie list from file? Y/N\n";
    std::getline(std::cin, inp);
    if (inp == "Y" || inp == "y" || inp == "yes" || inp == "YES")
        this->serv.read_from_json("movielist");
    else
        this->initialize_repo();

    std::cout << "Do you wish to load watch list from file? Y/N\n";
    std::getline(std::cin, inp);
    if (inp == "Y" || inp == "y" || inp == "yes" || inp == "YES")
        this->serv.read_from_json("watchlist");

    this->login();
}

void UI::login() {
    /*
     * Lets operator choose access mode (admin/user)*/
    bool cond = true;
    while (cond) {
        std::string str;
        std::cout << "Which mode do you wish to access?\n";
        std::getline(std::cin, str);
        if (str == "1" || str == "admin") {
            cond = false;
            //this->serv.write_to_json("movielist");
            //this->serv.read_from_json("movielist");
            this->adminmode();

        } else if (str == "2" || str == "user") {
            cond = false;
            this->usermode();

        } else
            std::cout << "Invalid input\n";
    }

}

void UI::adminmode() {
    /*
     * ADMIN access mode, where operator can add, remove, update movie list and save to JSON file*/
    std::string command;
    std::string title;
    std::string genre;
    std::string year;
    std::string likes;
    std::string trailer;

    while (true) {

        std::cout << "Admin cmmd:>";
        std::getline(std::cin, command);
        if (command == "add"){
            //sanitize trailer inputs to avoid malicious redirects / RCEs DONE
            std:: cout <<"Title: ";
            std::getline(std::cin, title);
            std::cout << "Genre: ";
            std::getline(std::cin, genre);
            std::cout << "Year: ";
            std::getline(std::cin, year);
            std::cout << "Likes: ";
            std::getline(std::cin, likes);
            std::cout << "Trailer: ";
            std::getline(std::cin, trailer);

            bool added = serv.add_s(title, genre, stoi(year), stoi(likes), trailer);
            if (!added)
                std::cout << "Invalid movie \n";
        }
        else if (command == "remove" || command == "rmv"){

            std::cout << "Title: ";
            std::getline(std::cin, title);
            std::cout << "Year: ";
            std::getline(std::cin, year);

            serv.remove_s(title, stoi(year));
        }
        else if (command == "update" || command == "updt"){
            std::cout << "Title: ";
            std::getline(std::cin, title);
            std::cout << "Year: ";
            std::getline(std::cin, year);


            std::cout << "Insert new data/>\n";
            std::string newtitle;
            std::string newgenre;
            std::string newtrailer;
            std::string newyear;
            std::string newlikes;

            std::cout <<"New Title: ";
            std::getline(std::cin, newtitle);
            std::cout << "New Genre: ";
            std::getline(std::cin, newgenre);
            std::cout << "New Year: ";
            std::getline(std::cin, newyear);
            std::cout << "New Likes: ";
            std::getline(std::cin, newlikes);
            std::cout << "New Trailer: ";
            std::getline(std::cin, newtrailer);

            serv.update_s(title, stoi(year), newtitle, newgenre, stoi(newyear), stoi(newlikes), newtrailer);
        }
        else if (command == "help"){
            std::cout << "List of commands:\n"
                         "\t1. add\n"
                         "\t2.remove || rmv \n"
                         "\t3.update || updt \n"
                         "\t4.list || ls \n"
                         "\t5.bck || out\n"
                         "\t6.exit || q \n"

                         "Make sure trailer redirects to domain https://www.youtube.com/\n";
        }
        else if (command == "ls" || command == "list"){
            DynamicVector *v;
            v = serv.getList_s();
            if (v->length() > 0) {
                for (int ind = 0; ind < v->length(); ind++) {
                    Movie tmpmov = v->getElem(ind);
                    std::cout << "Title: " << tmpmov.getTitle() << "\n";
                    std::cout << "Genre: " << tmpmov.getGenre() << "\n";
                    std::cout << "Year: " << tmpmov.getYear() << "\n";
                    std::cout << "Likes: " << tmpmov.getLikes() << "\n";
                    std::cout << "Trailer: " << tmpmov.getTrailer() << "\n";
                    std::cout << "\n";
                }
            }
            else
                std::cout << "Repository is empty\n";
        }
        else if (command == "bck" || command == "out") {
            std::string exitinp;
            std::cout << "Do you wish to save movie list to file? Y/N\n";
            std::getline(std::cin, exitinp);
            if (exitinp == "y" || exitinp == "Y" || exitinp == "yes" || exitinp == "YES")
                this->serv.write_to_json("movielist");
            this->login();
        }
        else if (command == "exit" || command == "q"){
            std::string exitinp;
            std::cout << "Do you wish to save movie list to file? Y/N\n";
            std::getline(std::cin, exitinp);
            if (exitinp == "y" || exitinp == "Y" || exitinp == "yes" || exitinp == "YES")
                this->serv.write_to_json("movielist");
            exit(0);
        }
        else {
            std::cout << "Invalid command\n";
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
}

void UI::usermode() {
    /*
     * USER access mode, where user can see movies by genre, add movies to watch list and save current
     * watch list to JSON file*/
    while(true){
        std::cout << "Welcome to the movie app!\n"
                     "\t1.See movies by genre\n"
                     "\t2.See watch list\n"
                     "\t3.Exit\n"
                     "\n"
                     "\tbck - back to login screen\n";
        std::string inp;
        std::getline(std::cin, inp);
        if (inp == "1"){
            std::string inpgenre;
            std::cout << "Insert movie genre: ";
            std::getline(std::cin, inpgenre);

            DynamicVector res = this->serv.movies_by_genre(inpgenre);
            for(int ind = 0; ind < res.length(); ind++)
            {
                std::string yn;
                std::cout << "Title: " << res.getElem(ind).getTitle() << "\n";
                std::cout << "Trailer: " << res.getElem(ind).getTrailer() << "\n";
                std::cout << "Click to watch\n";
                std::cout << "\n\n Did you like the trailer? y/n \n";
                std::getline(std::cin, yn);
                std::string title, genre, trailer;
                int likes, year;
                title = res.getElem(ind).getTitle();
                genre = res.getElem(ind).getGenre();
                year = res.getElem(ind).getYear();
                likes = res.getElem(ind).getLikes();
                trailer = res.getElem(ind).getTrailer();
                if (yn == "y" || yn == "Y" || yn == "Yes" || yn == "yes" || yn == "YES"){
                    this->serv.update_s(title, year, title, genre, year, likes+1, trailer);
                    this->serv.add_watch_s(title, genre, year, likes, trailer);
                }
                else if (yn == "q" || yn == "exit")
                    break;
            }
        }
        else if (inp == "2"){
            DynamicVector* watch;
            watch = this->serv.getwatchlist_s();
            if (watch->length() == 0)
                std::cout << "List is empty! \n";
            for (int ind = 0; ind < watch->length(); ind++)
            {
                std::cout << "Title: " << watch->getElem(ind).getTitle() << "\n";
                std::cout << "Genre: " << watch->getElem(ind).getGenre() << "\n";
                std::cout << "Year: " << watch->getElem(ind).getYear() << "\n";
                std::cout << "Likes: " << watch->getElem(ind).getLikes() << "\n";
                std::cout << "Trailer: " << watch->getElem(ind).getTrailer() << "\n";
                std::cout << "\n";
            }
        }
        else if (inp == "3"){
            std::string exitinp;
            std::cout << "Do you wish to save watch list to file? Y/N\n";
            std::getline(std::cin, exitinp);
            if (exitinp == "y" || exitinp == "Y" || exitinp == "yes" || exitinp == "YES")
                this->serv.write_to_json("watchlist");
            exit(0);
        }
        else if (inp == "bck" || inp == "out") {
            std::string exitinp;
            std::cout << "Do you wish to save watch list to file? Y/N\n";
            std::getline(std::cin, exitinp);
            if (exitinp == "y" || exitinp == "Y" || exitinp == "yes" || exitinp == "YES")
                this->serv.write_to_json("watchlist");

            this->login();
        }
        else {
            std::cout << "Invalid input\n";
        }
    }
}

UI::~UI() {

}