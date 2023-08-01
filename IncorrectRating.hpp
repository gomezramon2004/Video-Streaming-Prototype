#include <exception>

class IncorrectRating : public std::exception {
public:
    virtual const char* what() noexcept;
};