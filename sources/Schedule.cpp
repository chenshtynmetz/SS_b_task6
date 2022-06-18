#include "Schedule.hpp"
#include "iostream"//

namespace ariel{
    Schedule::Schedule(std::vector<Team*> t){
        this->teams = t;
        this->cycle = {};
        int len = this->teams.size();
        //any team play 2 times against all the teams.
        for(unsigned i=0; i<((len-1)*2); i++){
            this->cycle.push_back({});
        }
        std::cout << this->cycle.size() << '\n';
        // std::cout << (len-1)*2 << '\n';
        create_sch();
    }

    Schedule& Schedule::create_sch(){
        unsigned len = this->teams.size();
        unsigned k = 0;
        bool flag = false;
        for(unsigned i = 0; i<len; ){
            for(unsigned j = i+1; j<len; j++){ //maybe from i+1
                //the i team is out team
                if(flag){
                    Game g{this->teams.at(j), this->teams.at(i)}; //build game in somwhere else
                    this->cycle.at(k).emplace_back(&g);
                    std::cout << g.the_winner()->get_name() << '\n';
                    std::cout << "done" << '\n';
                }
                //the i team is home team
                else{
                    Game g{this->teams.at(i), this->teams.at(j)};
                    this->cycle.at(k).emplace_back(&g);
                }
                k++;
            }
            if(flag){
                i++;
                flag = false;
                k = 0; //need to return k to 0 in another place?
            }
            else{
                flag = true;
            }
        }
        return *this;
    }
}