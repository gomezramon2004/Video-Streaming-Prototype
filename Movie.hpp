#pragma once

#include "Video.hpp"

class Movie: public Video{
public:
    Movie();
    Movie(int, std::string, int, std::string);
    std::string show() override;
    virtual ~Movie();
};