#include "Video.hpp"

Video::Video(): ID(0), name(""), duration(0), genre(""), average_rating(0){};

Video::Video(int ID, std::string name, int duration, std::string genre): ID(ID), name(name), duration(duration), genre(genre), average_rating(0){};

std::string Video::getName(){
    return this->name;
}

std::string Video::getGenre(){
    return this->genre;
}

int Video::getAverageRating(){
    return this->average_rating;
}

void Video::rate(int& rating){
    this->ratings.push_back(rating);
}

void Video::updateAverageRating(){
    int sum = 0;
    for (int i = 0; i < this->ratings.size(); i++){
        sum += this->ratings[i];
    }
    this->average_rating = sum / this->ratings.size();
}

void Video::operator+(int& num) {
    this->average_rating + num;
}

Video::~Video(){};