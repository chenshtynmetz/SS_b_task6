#pragma once
#include <string>
#include "Team.hpp"

namespace ariel{
    class Game{
        private:
            Team* home_team;
            Team* out_team;
            Team* winner;
            Team* loser;
            int home_result;
            int out_result;
        public:
            Game(Team* home, Team* out); //construcor
            Team* the_winner(); //return the winner
            Game& play_game();
            Team* get_loser();
    };
}