#include <exception>

class NoStructureCorrect : public std::exception {
public:
    virtual const char* what() noexcept;
};