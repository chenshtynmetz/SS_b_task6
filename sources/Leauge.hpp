#pragma once
#include <string>
#include <vector>
#include "Schedule.hpp"

namespace ariel{
    class Leauge{
        private:
            std::vector<Team*> teams;
            Schedule* my_sched;
            unsigned curr_cycle;
            unsigned curr_game;
            Team* temp_team;
            std::vector<Team*> by_win;
            std::vector<Team*> by_basket;
            bool activate;
            std::vector<std::string> order_win;
            std::vector<std::string> order_lose;
        public:
            //random constructor
            Leauge();
            //constructor and half random constructor
            Leauge(std::vector<Team*> t);
            //create schedule to the leauge
            Leauge& make_sched();
            Leauge& start_leauge();
            Leauge& present_statistic();
            int max_win();
            int max_lose();
            int num_positive_basket();
    };
}