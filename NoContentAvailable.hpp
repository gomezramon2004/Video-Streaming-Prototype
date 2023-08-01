#include <exception>

class NoContentAvailable : public std::exception {
public:
    virtual const char* what() noexcept;
};