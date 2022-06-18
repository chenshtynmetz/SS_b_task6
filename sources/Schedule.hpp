#pragma once
#include <vector>
#include "Game.hpp"


namespace ariel{
    class Schedule{
        private:
            std::vector<Team*> teams;
            // std::vector<std::vector<Game*>> cycle; // ???
        public:
            std::vector<std::vector<Game*>> cycle;
            Schedule(std::vector<Team*> t); //constructor
            Schedule& create_sch(); 
    };
}