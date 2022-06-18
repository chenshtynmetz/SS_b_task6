#include "Game.hpp"
#include <iostream>
#include <random>

namespace ariel{
    //constructor
    Game::Game(Team* home, Team* out){
        this->home_team = home;
        this->out_team = out;
        this->winner = NULL;
        this->home_result = 0;
        this->out_result = 0;
    }
    //return the winner
    Team* Game::the_winner(){
        //in tie the out team win
        if(this->out_result >= this->home_result){
            this->winner = this->out_team;
        }
        else{
            this->winner = this->home_team;
        }
        this->winner->increase_win();
        return this->winner;
    }

    //play the game, random by normal distribution
    Game& Game::play_game(){
        // std::cout << "h" << '\n';
        int min = 50;
        int max = 100;
        int home_min = 55;
        double exp;
        double var;
        double res;
        int cast_res;
        //out team result
        exp = (min+max)/2;
        var = (max-min)/2;
        std::random_device rand{};
        std::mt19937 g{rand()};
        std::normal_distribution<> distribution{exp, var};
        res = std::round(distribution(g));
        std::cout << res << '\n';
        cast_res = static_cast<int>(res); 
        std::cout << cast_res << '\n';
        this->out_result = cast_res; //this is the problem!!!!!!!!!!!!!!!!
        std::cout << "hi" << '\n';
        //home team result
        exp = (home_min+max)/2;
        var = (max-home_min)/2;
        std::normal_distribution<> distribution2{exp, var};
        res = std::round(distribution2(g));
        this->home_result = (int)res;
        //add 10 points by talent
        if(this->home_team->get_talent() > this->out_team->get_talent()){
            this->home_result += 10;
        }
        else{
            this->out_result += 10;
        }
        this->home_team->add_baskets(this->home_result, this->out_result);
        this->out_team->add_baskets(this->out_result , this->home_result);
        // std::cout << this->out_result << '\n';
        return *this;
    }
    Team* Game::get_loser(){
        return this->loser;
    }
}