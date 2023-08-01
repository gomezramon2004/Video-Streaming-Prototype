#include "Series.hpp"

Series::Series(): Video() {}

Series::Series(int ID, std::string name, int duration, std::string genre): Video{ID, name, duration, genre} {}

std::string Series::show(){
    std::string result = "";
    result += "ID: " + std::to_string(this->ID) + "\n";
    result += "Name: " + this->name + "\n";
    result += "Duration: " + std::to_string(this->duration) + "\n";
    result += "Genre: " + this->genre + "\n";
    result += "Average rating: " + std::to_string(this->average_rating);

    for (int i = 0; i < this->episodes.size(); i++){
        result += "\n";
        result += "Episode Name: " + this->episodes[i].getNameEpisode() + "\n";
        result += "Season: " + std::to_string(this->episodes[i].getSeason());
    }

    return result;
}

std::string Series::show(Episode ep){
    std::string result = "";
    result += "Episode Name: " + ep.getNameEpisode() + "\n";
    result += "Season: " + std::to_string(ep.getSeason());
    return result;
}   

void Series::addEpisode(Episode ep){
    this->episodes.push_back(ep);
}

Series::~Series(){};