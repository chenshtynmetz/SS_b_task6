#pragma once
#include <string>

namespace ariel{
    class Team{
        private:
            std::string name;
            double talent;
            int num_wins;
            int bad_baskets;
            int good_baskets;
        public:
            Team(std::string n, double t); //constructor
            Team(); // random constructor
            std::string get_name();
            double get_talent();
            Team& increase_win();
            int get_wins();
            Team& add_baskets(int good, int bad);
            int get_baskets();
    };
}