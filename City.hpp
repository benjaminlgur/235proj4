//Benjamin Gur CSCI 235 Project 4

#ifndef CITY_
#define CITY_
#include<string>
#include<iostream>
#include<vector>

class City { 
public:
    City(std::string name);
    void addRoute(City* city);
    std::string getName();
    bool vistCheck();
    void visitSet();
    int numberOfRoutes();
    City* getRoute(int route_number);
    int numberRoutesVisted();
    



private:
    std::string name_;
    bool visited_;
    std::vector<City*> open_routes_;
    
};




#endif