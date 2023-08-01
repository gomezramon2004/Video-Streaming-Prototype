#pragma once

#include <string>

class Episode{
private:
    std::string name_episode;
    int season;
public:
    Episode();
    Episode(std::string, int);
    std::string getNameEpisode();
    int getSeason();
};