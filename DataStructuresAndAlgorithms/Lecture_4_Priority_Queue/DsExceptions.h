#ifndef DSEXCEPTIONS_H
#define DSEXCEPTIONS_H

#include <stdexcept>

class UnderflowException : public std::runtime_error {
    public:
    UnderflowException() : std::runtime_error("UnderflowException! Can't perform function on empty heap") {}
};

#endif // DSEXCEPTIONS_H