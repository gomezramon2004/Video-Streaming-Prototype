#pragma once

#include <vector>
#include <string>

class Video{
protected:
    int ID;
    std::string name;
    int duration;
    std::string genre;
    std::vector <int> ratings;
    int average_rating;
public:
    Video();
    Video(int, std::string, int, std::string);
    std::string getName();
    std::string getGenre();
    int getAverageRating();
    void rate(int&);
    void updateAverageRating();
    virtual std::string show()=0;
    void operator+(int&);
    virtual ~Video();
};