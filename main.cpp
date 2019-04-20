#include <iostream>

int main(){
    int start_city, end_city;
    std::cout << "input start city number indexed from 0\n"; 
    std::cin << start_city;
    std::cout << "input end city number indexed from 0\n";
    RouteMap a;
    a.readMap("input.csv");
    a.findRoute(a.getCity(start_city), a.getCity(end_city));
}