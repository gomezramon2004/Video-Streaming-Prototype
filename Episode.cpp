#include "Episode.hpp"
#include <string>

Episode::Episode(): name_episode(""), season(0){};

Episode::Episode(std::string n, int s): name_episode(n), season(s){};

std::string Episode::getNameEpisode(){
    return this->name_episode;
}

int Episode::getSeason(){
    return this->season;
}
