//Benjamin Gur CSCI 235 Project 4

#include "City.hpp"

City::City(std::string name) : name_(name), visited_(false) {
} //end constructor

std::string City::getName(){
    return name_;
}

void City::addRoute(City* city){
    open_routes_.push_back(city);
}

bool City::vistCheck(){
    return visited_;
}

void City::visitSet(){
    visited_ = true;
}

int City::numberOfRoutes(){
    return open_routes_.size();
}

City* City::getRoute(int route_number){
    return open_routes_[route_number];
}

int City::numberRoutesVisted(){
    int numberVisited; 
    for(int i = 0; i < numberOfRoutes() - 1; i++){
        if (getRoute(i)->vistCheck()){
            numberVisited++;
        }
    }
}