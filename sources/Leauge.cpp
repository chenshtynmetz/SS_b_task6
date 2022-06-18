#include "Leauge.hpp"
#include <iostream>
#include <algorithm>

namespace ariel{
    //random constructor
    Leauge::Leauge(){
        this->teams = {};
        for(unsigned i = 0; i < 19; i++){
            Team t = Team();
            this->temp_team = &t;
            this->teams.push_back(this->temp_team);
        }
        make_sched();
        this->curr_cycle = 1;
        this->curr_game = 0;
        this->by_basket = this->teams;
        this->by_win = this->teams;
        this->activate = false;
        this->order_win = {};
        this->order_lose = {};
    }
    //constructor
    Leauge::Leauge(std::vector<Team*> t){
        this->teams = t;
        unsigned len = t.size();
        if(len == 0){
            len= 1;
        }
        //if the sum of the teams < 20, create more teams
        if(len < 20){
            for(unsigned i = len-1; i < 19; i++){
                Team t = Team();
                this->temp_team = &t;
                this->teams.push_back(this->temp_team);
            }
        }
        // std::cout<< "in l" << '\n';
        make_sched();
        this->curr_cycle = 1;
        this->curr_game = 0;
    }
    Leauge& Leauge::make_sched(){
        Schedule s = Schedule(this->teams);
        // std::cout<< "sched" << '\n';
        this->my_sched = &s;
        return *this;
    }
    Leauge& Leauge::start_leauge(){
        unsigned sum_cycle = this->my_sched->cycle.size();
        unsigned len = 10; 
        std::cout << sum_cycle << '\n';
        for(unsigned i = 0; i<sum_cycle; i++){
            for(unsigned j = 0; j<len; j++){
                // std::cout << this->my_sched->cycle.at(i).at(j)->the_winner() << '\n';
                this->my_sched->cycle.at(i).at(j)->play_game();
                std::cout << "play" << '\n';
                this->order_win.push_back(this->my_sched->cycle.at(i).at(j)->the_winner()->get_name());
                this->order_lose.push_back(this->my_sched->cycle.at(i).at(j)->get_loser()->get_name());
            }
        }
        std::cout << "hi" << '\n';
        this->activate = true;
        return *this;
    }
    int Leauge::max_win(){
        int max_seq = 0;
        int curr_seq = 1;
        std::string last_win = this->order_win.at(0);
        std::string max_win;
        for(unsigned i = 1; i<this->order_win.size(); i++){
            if(last_win == this->order_win.at(i)){
                curr_seq++;
            }
            else{
                curr_seq = 1;
            }
            last_win = this->order_win.at(i);
            if(curr_seq > max_seq){
                max_seq = curr_seq;
                max_win = last_win;
            }
        }
        return max_seq;
    }

    int Leauge::max_lose(){
        int max_seq = 0;
        int curr_seq = 1;
        std::string last_lose = this->order_lose.at(0);
        std::string max_lose;
        for(unsigned i = 1; i<this->order_lose.size(); i++){
            if(last_lose == this->order_lose.at(i)){
                curr_seq++;
            }
            else{
                curr_seq = 1;
            }
            last_lose = this->order_lose.at(i);
            if(curr_seq > max_seq){
                max_seq = curr_seq;
                max_lose = last_lose;
            }
        }
        return max_seq;
    }
    int Leauge::num_positive_basket(){
        int count = 0;
        for(unsigned i = 0; i<this->teams.size(); i++){
            if(this->teams.at(i)->get_baskets() > 0){
                count++;
            }
        }
        return count;
    }
    Leauge& Leauge::present_statistic(){
        if(!this->activate){
            std::cout << "please play the leauge first" << std::endl;
            return *this;
        }
        int num_of_leaders;
        //sort by wins
        std::sort (this->by_win.begin(), this->by_win.end(), [](Team* t1, Team* t2) { return t1->get_wins() >= t2->get_wins();});
        std::sort (this->by_basket.begin(), this->by_basket.end(), [](Team* t1, Team* t2) { return t1->get_baskets() >= t2->get_baskets();});
        int max_win = this->max_win();
        int max_lose = this->max_lose();
        int num_of_positive = this->num_positive_basket();
        std::cout << "how much leader group you wont see?" << std::endl;
        std::cin >> num_of_leaders;
        std::cout << "Statistics:"  << std::endl;
        std::cout << "By winners:"  << std::endl;
        for(unsigned i = 0; i<this->by_win.size(); i++){
            std::cout << i+1 << ": " << this->by_win.at(i)->get_name() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "By baskets:"  << std::endl;
        for(unsigned i = 0; i<this->by_basket.size(); i++){
            std::cout << i+1 << ": " << this->by_basket.at(i)->get_name() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "The leaders of the leauge is: " << std::endl;
        for(unsigned i=0; i<this->by_win.size(); i++){
            std::cout << this->by_win.at(i) << " ";
        }
        std::cout << std::endl;
        std::cout << "The longest winning streak is" << max_win << std::endl;
        std::cout << "The longest losing streak is" << max_lose << std::endl;
        std::cout << num_of_positive << " teams score more than absorbed" << max_win << std::endl;
        return *this;
    }
}