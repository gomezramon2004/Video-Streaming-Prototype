#include "Movie.hpp"

Movie::Movie(): Video(){}

Movie::Movie(int ID, std::string name, int duration, std::string genre): Video{ID, name, duration, genre} {}

std::string Movie::show(){
    std::string result = "";
    result += "ID: " + std::to_string(this->ID) + "\n";
    result += "Name: " + this->name + "\n";
    result += "Duration: " + std::to_string(this->duration) + "\n";
    result += "Genre: " + this->genre + "\n";
    result += "Average rating: " + std::to_string(this->average_rating);
    return result;
}

Movie::~Movie(){};