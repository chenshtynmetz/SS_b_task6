#include "Team.hpp"
#include <iostream>

namespace ariel{
    //constructor
    Team::Team(std::string n, double t){
        this->name = n;
        this->talent = t;
        this->num_wins = 0;
        this->bad_baskets = 0;
        this->good_baskets = 0;
    }
    //random constructor
    Team::Team(){
        int size = rand() % 10 + 1;
        std::string name;
        char c;
        for(int i=0; i<size; i++){
            c = 'a' + rand()%26;
            name += c;
        }
        this->name = name;
        double t = ((double) rand() / (RAND_MAX)) + 1;
        this->talent = t;
        // std::cout << t << '\n';
        // std::cout << name << '\n';
    }
    std::string Team::get_name(){
        return this->name;
    }
    double Team::get_talent(){
        return this->talent;
    }
    Team& Team::increase_win(){
        this->num_wins++;
        return *this;
    }
    int Team::get_wins(){
        return this->num_wins;
    }
    Team& Team::add_baskets(int good, int bad){
        this->good_baskets += good;
        this->bad_baskets += bad;
        return *this;
    }
    int Team::get_baskets(){
        int baskets = this->good_baskets - this->bad_baskets;
        return baskets;
    }
}