#ifndef __OPERATORS_H__
#define __OPERATORS_H__

#include "libraries.hpp"
#include "node.hpp"
#include "exception.hpp"

void checkInputsNumber(int maximumInputsAvailable, int inputsConnected);

class Operator : public Node
{
public:
    Operator(const size_t id, const size_t fatherId);
    virtual int evaluateNode() = 0;
};

class Sum : public Operator
{
public:
    Sum(const size_t id, const size_t fatherId);
    int evaluateNode();
};

class Mult : public Operator
{
public:
    Mult(const size_t id, const size_t fatherId);
    int evaluateNode();
};

class Negative : public Operator
{
public:
    Negative(const size_t id, const size_t fatherId);
    int evaluateNode();
};

class Med : public Operator
{
public:
    Med(const size_t id, const size_t parentId);
    int evaluateNode();
};

#endif