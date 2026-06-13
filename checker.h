#ifndef CHECKER_H
#define CHECKER_H
#include <stdexcept>
#include <string>
class InvalidInput : public std::runtime_error {
    public:
        explicit InvalidInput(const std::string& message)
            : std::runtime_error("Ошибка ввода: " + message) {}
};
#endif