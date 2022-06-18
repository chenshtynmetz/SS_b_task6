#include <iostream>
#include <vector>
#include <string>
#include "Leauge.hpp"
#include "Team.hpp"

using namespace ariel;
int main(){
    std::vector<Team*> teams = {};
    std::string name;
    double talent;
    std::cout << "Create a leauge:" << std::endl;
    for(unsigned i=0; i<20; i++){
        std::cout << "Enter the team name (if you want to stop press 'x'):" << std::endl;
        std::cin >> name;
        if(name == "x"){
            break;
        }
        std::cout << "Enter the team talent (number betweem 0 to 1):" << std::endl;
        std::cin >> talent;
        Team temp = Team(name, talent);
        teams.push_back(&temp);
    }
    // std::cout<< "create l" << '\n';
    Leauge l = Leauge(teams);
    std::cout<< "finish l" << '\n';
    l.start_leauge();
    l.present_statistic();
    return 0;
}