////
//// Created by ANDREI on 20-Mar-24.
////
//
////#include <string>
//#include <string.h>
//#include <iostream>
//
//#include <string>
//#include <cctype>
//#include <limits>
//#include <stdlib.h>
//#include "ui.h"
//#include "../Services/services.h"
//
//
//
//UI::UI(Services* serv) : serv{serv}{
//
//}
//
//void UI::savemovies() {
//
//}
//
//void UI::savewatch() {
//
//}
//
//void UI::start() {
//    /*
//     * Asks if operator wishes to load movie/watch lists from JSON files and then proceeds
//     * to login menu*/
//    std::string inp;
//    this->initialize_output_type();
//
//    std::cout << "Do you wish to load movie list from JSON file? Y/N\n";
//    std::getline(std::cin, inp);
//    if (inp == "Y" || inp == "y" || inp == "yes" || inp == "YES")
//        this->serv.read_from_file_s(this->serv.getList_s(), "movielist.json");
//    else
//        this->initialize_repo();
//
//    std::cout << "Do you wish to load watch list from JSON file? Y/N\n";
//    std::getline(std::cin, inp);
//    if (inp == "Y" || inp == "y" || inp == "yes" || inp == "YES")
//        this->serv.read_from_json("watchlist", "watchlist.json");
//
//    this->login();
//}
//
//void UI::initialize_output_type() {
//    //initializes the file output type (CSV/HTML)
//    std::string inp;
//    while (true){
//        std::cout << "Choose watchlist output file format: \n"
//                     "\t1.CSV\n"
//                     "\t2.HTM\n";
//        std::getline(std::cin, inp);
//        if (inp == "1"){
//            this->outputfiletype = "CSV";
//            this->serv.set_output_type(".csv");
//            break;
//        }
//        else if (inp == "2")
//        {
//            this->outputfiletype = "HTML";
//            this->serv.set_output_type(".html");
//            break;
//        }
//        else std::cout << "Invalid input\n";
//    }
//}
//
//void UI::login() {
//    /*
//     * Lets operator choose access mode (admin/user)*/
//    bool cond = true;
//    while (cond) {
//        std::string str;
//        std::cout << "Which mode do you wish to access?\n";
//        std::getline(std::cin, str);
//        if (str == "1" || str == "admin") {
//            cond = false;
//            //this->serv.write_to_json("movielist");
//            //this->serv.read_from_json("movielist");
//            this->adminmode();
//
//        } else if (str == "2" || str == "user") {
//            cond = false;
//            this->usermode();
//
//        } else
//            std::cout << "Invalid input\n";
//    }
//
//}
//
//void UI::adminmode() {
//    /*
//     * ADMIN access mode, where operator can add, remove, update movie list and save to JSON file*/
//    std::string command;
//    std::string title;
//    std::string genre;
//    std::string year;
//    std::string likes;
//    std::string trailer;
//
//    while (true) {
//
//        std::cout << "Admin cmmd:>";
//        std::getline(std::cin, command);
//        if (command == "add"){
//            std:: cout <<"Title: ";
//            std::getline(std::cin, title);
//            std::cout << "Genre: ";
//            std::getline(std::cin, genre);
//            std::cout << "Year: ";
//            std::getline(std::cin, year);
//            std::cout << "Likes: ";
//            std::getline(std::cin, likes);
//            std::cout << "Trailer: ";
//            std::getline(std::cin, trailer);
//
//            bool added = serv.add_s(title, genre, stoi(year), stoi(likes), trailer);
//            if (!added)
//                std::cout << "Invalid movie \n";
//        }
//        else if (command == "remove" || command == "rmv"){
//
//            std::cout << "Title: ";
//            std::getline(std::cin, title);
//            std::cout << "Year: ";
//            std::getline(std::cin, year);
//
//            serv.remove_s(title, stoi(year));
//        }
//        else if (command == "update" || command == "updt"){
//            std::cout << "Title: ";
//            std::getline(std::cin, title);
//            std::cout << "Year: ";
//            std::getline(std::cin, year);
//
//
//            std::cout << "Insert new data/>\n";
//            std::string newtitle;
//            std::string newgenre;
//            std::string newtrailer;
//            std::string newyear;
//            std::string newlikes;
//
//            std::cout <<"New Title: ";
//            std::getline(std::cin, newtitle);
//            std::cout << "New Genre: ";
//            std::getline(std::cin, newgenre);
//            std::cout << "New Year: ";
//            std::getline(std::cin, newyear);
//            std::cout << "New Likes: ";
//            std::getline(std::cin, newlikes);
//            std::cout << "New Trailer: ";
//            std::getline(std::cin, newtrailer);
//
//            serv.update_s(title, stoi(year), newtitle, newgenre, stoi(newyear), stoi(newlikes), newtrailer);
//        }
//        else if (command == "help"){
//            std::cout << "List of commands:\n"
//                         "\t1. add\n"
//                         "\t2.remove || rmv \n"
//                         "\t3.update || updt \n"
//                         "\t4.list || ls \n"
//                         "\t5.bck || out\n"
//                         "\t6.exit || q \n"
//
//                         "Make sure trailer redirects to domain https://www.youtube.com/\n";
//        }
//        else if (command == "ls" || command == "list"){
//            std::vector<Movie> *v;
//            v = serv.getList_s();
//            if (!v->empty()) {
//                for (auto& tmpmov : *v) {
//                    std::cout << "Title: " << tmpmov.getTitle() << "\n";
//                    std::cout << "Genre: " << tmpmov.getGenre() << "\n";
//                    std::cout << "Year: " << tmpmov.getYear() << "\n";
//                    std::cout << "Likes: " << tmpmov.getLikes() << "\n";
//                    std::cout << "Trailer: " << tmpmov.getTrailer() << "\n";
//                    std::cout << "\n";
//                }
//            }
//            else
//                std::cout << "Repository is empty\n";
//        }
//        else if (command == "bck" || command == "out") {
//            std::string exitinp;
//            std::cout << "Do you wish to save movie list to file? Y/N\n";
//            std::getline(std::cin, exitinp);
//            if (exitinp == "y" || exitinp == "Y" || exitinp == "yes" || exitinp == "YES")
//                this->serv.write_to_json("movielist", "movielist.json");
//            this->login();
//        }
//        else if (command == "exit" || command == "q"){
//            std::string exitinp;
//            std::cout << "Do you wish to save movie list to file? Y/N\n";
//            std::getline(std::cin, exitinp);
//            if (exitinp == "y" || exitinp == "Y" || exitinp == "yes" || exitinp == "YES")
//                this->serv.write_to_json("movielist", "movielist.json");
//            exit(0);
//        }
//        else {
//            std::cout << "Invalid command\n";
//            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//        }
//    }
//}
//
//void UI::usermode() {
//    /*
//     * USER access mode, where user can see movies by genre, add movies to watch list and save current
//     * watch list to JSON file*/
//    while(true){
//        std::cout << "Welcome to the movie app!\n"
//                     "\t1.See movies by genre\n"
//                     "\t2.See watch list\n"
//                     "\t3.Display watch list\n"
//                     "\t9.Exit\n"
//                     "\n"
//                     "\tbck - back to login screen\n";
//        std::string inp;
//        std::getline(std::cin, inp);
//        if (inp == "1"){
//            std::string inpgenre;
//            std::cout << "Insert movie genre: ";
//            std::getline(std::cin, inpgenre);
//
//            std::vector<Movie> res = this->serv.movies_by_genre(inpgenre);
//            for( auto& ind : res)
//            {
//                std::string yn;
//                std::cout << "Title: " << ind.getTitle() << "\n";
//                std::cout << "Trailer: " << ind.getTrailer() << "\n";
//                std::cout << "Click to watch\n";
//                std::string cmd = "start " + ind.getTrailer(); //Windows solution
//                // std::string cmd = "open " + res.at(ind).getTrailer(); Linux solution
//                //todo use qt?
//                system(cmd.c_str());
//                std::cout << "\n\n Did you like the trailer? y/n \n";
//                std::getline(std::cin, yn);
//                std::string title, genre, trailer;
//                int likes, year;
//                title = ind.getTitle();
//                genre = ind.getGenre();
//                year = ind.getYear();
//                likes = ind.getLikes();
//                trailer = ind.getTrailer();
//                if (yn == "y" || yn == "Y" || yn == "Yes" || yn == "yes" || yn == "YES"){
//                    this->serv.update_s(title, year, title, genre, year, likes+1, trailer);
//                    this->serv.add_watch_s(title, genre, year, likes, trailer);
//                }
//                else if (yn == "q" || yn == "exit")
//                    break;
//            }
//        }
//        else if (inp == "2"){
//            std::vector<Movie>* watch;
//            watch = this->serv.getwatchlist_s();
//            if (watch->empty())
//                std::cout << "List is empty! \n";
//            for ( auto& ind : *watch)
//            {
//                std::cout << "Title: " << ind.getTitle() << "\n";
//                std::cout << "Genre: " << ind.getGenre() << "\n";
//                std::cout << "Year: " << ind.getYear() << "\n";
//                std::cout << "Likes: " << ind.getLikes() << "\n";
//                std::cout << "Trailer: " << ind.getTrailer() << "\n";
//                std::cout << "\n";
//            }
//        }
//        else if (inp == "3"){
//            this->serv.output_write_handler("watchlist");
//            std::string starter;
//            if ( this->outputfiletype == "CSV"){
//                starter = "";
//            }
//            else starter = "start ";
//            std::string cmd = starter + "..\\Services\\" + this->outputfiletype + "saves\\watchlist" +
//                    this->serv.get_outputfile_ext();
//            system(cmd.c_str());
//        }
//        else if (inp == "9"){
//            std::string exitinp;
//            std::cout << "Do you wish to save watch list to file? Y/N\n";
//            std::getline(std::cin, exitinp);
//            if (exitinp == "y" || exitinp == "Y" || exitinp == "yes" || exitinp == "YES")
//                this->serv.write_to_json("watchlist", "watchlist.json");
//            exit(0);
//        }
//        else if (inp == "bck" || inp == "out") {
//            std::string exitinp;
//            std::cout << "Do you wish to save watch list to file? Y/N\n";
//            std::getline(std::cin, exitinp);
//            if (exitinp == "y" || exitinp == "Y" || exitinp == "yes" || exitinp == "YES")
//                this->serv.write_to_json("watchlist", "watchlist.json");
//
//            this->login();
//        }
//        else {
//            std::cout << "Invalid input\n";
//        }
//    }
//}
//
//UI::~UI() {
//
//}