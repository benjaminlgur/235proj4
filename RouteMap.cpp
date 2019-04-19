//Benjamin Gur CSCI 235 Project 4

#include "RouteMap.hpp"


RouteMap::RouteMap(){
}; //end constructor

City* RouteMap::getCity(size_t position){ 
    if (position <= numberOfCitys())
        std::cout << "Catching";
    assert(position <= numberOfCitys());
}

bool RouteMap::readMap(std::string input_file_name){ 
    std::ifstream file;
    file.open(input_file_name);
    if(file.is_open() == false){
        std::cout << "Catching";
        return false;
    }
    if(emptyFileTest(file))
        std::cout << "Catching";
    assert(emptyFileTest(file) == false);
    std::string read;
    while(read.find('-') == std::string::npos){ //first line while loop
        std::getline(file, read, ',');
        if(read.find('-') != std::string::npos)
            break;
        City* city_ptr = new City(read);
        all_citys_.push_back(city_ptr);
    } //end while

    while(read.find('\n') != std::string::npos){
        read.pop_back(); //c++ 11
    }
    City* last_city_ptr = new City(read);
    all_citys_.push_back(last_city_ptr);

    //closing file and reopening.
    file.close();
    std::ifstream file2;
    file2.open(input_file_name);
    std::getline(file2, read); //trashing first line.
    
    std::string city1, city2;
    int city1_pos, city2_pos;
    while(!file2.eof()){ 
        std::getline(file2, city1, '-');
        std::getline(file2, city2, ',');
        for(int i = 0; i < all_citys_.size(); i++){ //might need to do size - 1
            if(getCity(i)->getName() == city1){
                city1_pos = i;
                break; 
            }
        }
        for(int j = 0; j < all_citys_.size(); j++){ //might need to do size - 1
            if(getCity(j)->getName() == city2){
                city2_pos = j;
                break;
            }
        }

        getCity(city1_pos)->addRoute(getCity(city2_pos));
        //uncomment below line if needed
        //getCity(city2_pos)->addRoute(getCity(city1_pos));
    }//end while
}


bool RouteMap::isRoute(City* origin, City* destination){
    route.push(origin);
    origin->visitSet();
    while(route.top() != destination){
        bool broke = false;
        for(int i = 0; i < route.top()->numberOfRoutes(); i++){
            if(route.top()->getRoute(i)->vistCheck() == false){
                route.push(route.top()->getRoute(i));
                route.top()->visitSet();
                broke = true;
                break;
            }
        } //end for
        
        if(route.top() == destination){
            printResults();
            return true;
        }
        if (route.top() == origin && broke == false)
            return false;
        if (route.top() != origin && broke == false) 
            route.pop();
         
    } //end while
    printResults();
    return true;  
}

void RouteMap::printResults(){
    std::stack<std::string> directions;
    while(!route.empty()){
        directions.push(route.top()->getName());
        route.pop();
    }
    while(!directions.empty()){
        std::cout << directions.top();
        directions.pop();
        if(!directions.empty())
            std::cout << " -> ";
    }
    std::cout << std::endl;
}

int RouteMap::numberOfCitys(){
    return all_citys_.size();
}


bool RouteMap::emptyFileTest(std::ifstream& pFile){
    return pFile.peek() == std::ifstream::traits_type::eof();
}