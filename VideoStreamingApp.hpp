#pragma once

#include <string>
#include <vector>
#include "Video.hpp"
#include "Movie.hpp"
#include "Series.hpp"

class VideoStreamingApp{
private:    
    std::vector <Video*> videos;
public:
    VideoStreamingApp();
    void start();
    void fileUpload(std::string);
    void searchVideoToRate(std::string, int);
    std::string graphInterface();
    std::string genreOrRating();
};