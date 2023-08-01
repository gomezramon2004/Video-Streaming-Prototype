#include "IncorrectRating.hpp"

const char* IncorrectRating::what() noexcept {
    return "Error: Incorrect rating. Must be between 1 and 5";
}