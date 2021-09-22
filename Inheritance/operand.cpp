#include "operand.hpp"

Operand::Operand(const size_t id, const size_t fatherId, const int number)
    : Node(id, fatherId)
{
    value =  number;
}
int Operand::evaluateNode()
{
    return value;
}