#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "libraries.hpp"

class Exception
{
public:
    virtual void what() = 0;
};

class wrongNodeId : public Exception
{
public:
    virtual void what()
    {
        cerr << "Duplicate node ID.\n" << endl;
    }
};

class wrongParentId : public Exception
{
public:
    virtual void what()
    {
        cerr << "Parent node not found.\n" << endl;
    }
};

class invalidTreeStructure : public Exception
{
public:
    virtual void what()
    {
        cerr << "Invalid tree structure.\n" << endl;
    }
};

class invalidParent : public Exception
{
public:
    virtual void what()
    {
        cerr << "Invalid parent.\n" << endl;
    }
};

class operandChild : public invalidParent
{

};

class rootChildExceed : public invalidParent
{

};

#endif