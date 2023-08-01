#pragma once

#include "Video.hpp"
#include "Episode.hpp"

class Series: public Video{
private:
    std::vector <Episode> episodes;
public:
    Series();
    Series(int, std::string, int, std::string);  
    std::string show() override;
    std::string show(Episode);
    void addEpisode(Episode);
    virtual ~Series();
};