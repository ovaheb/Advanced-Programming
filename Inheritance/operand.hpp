#ifndef __OPERAND_H__
#define __OPERAND_H__

#include "libraries.hpp"
#include "exception.hpp"
#include "node.hpp"

class Operand : public Node
{
public:
	Operand(const size_t id, const size_t fatherId, const int number);
	int evaluateNode();
private:
	int value;
};

#endif