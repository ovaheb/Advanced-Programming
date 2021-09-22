#include "tree.hpp"

Tree::Tree()
{
    root = NULL;
}
void Tree::add_operand_node(const size_t id, const size_t fatherId, const int value){
    try
    {
        Exception* exception;
        if (fatherId == DUMMY_ROOT)
        {
            if (root == NULL)
            {
                root = new Operand(id, fatherId, value);
                return;
            }
            else
            {
                exception = new rootChildExceed();
                throw exception;
            }
        }
        else
        {
            Node* parentNode = root->findNode(fatherId);
            if (parentNode == NULL)
            {
                exception = new wrongParentId();
                throw exception;
            }
            if (root->findNode(id) != NULL)
            {
                exception = new wrongNodeId();
                throw exception;
            }
            Operand* node = dynamic_cast<Operand*>(parentNode);
            if (node)
            {
                exception = new operandChild();
                throw exception;
            }
            Node* child_node = new Operand(id, fatherId, value);
            parentNode->addNode(child_node);
        }   
    }
    catch(Exception* exception)
    {
        exception->what();
        exit(FAIL);
    }
}
Node* Tree::createNewOperator(const size_t id, const size_t fatherId, const OperatorType type)
{
    Node* child_node;
    switch (type)
    {
        case Add:
            child_node = new Sum(id, fatherId);
            break;
        case Multiply:
            child_node = new Mult(id, fatherId);
            break;
        case Not:
            child_node = new Negative(id, fatherId);
            break;
        case Median:
            child_node = new Med(id, fatherId);
            break;
    }
    return child_node;
}
void Tree::add_operator_node(const size_t id, const size_t fatherId, const OperatorType type)
{
    try
    {
        Exception* exception;
        if (fatherId == DUMMY_ROOT)
        {
            if (root == NULL)
            {
                root = createNewOperator(id, fatherId, type);
                return;
            }
            exception = new rootChildExceed();
            throw exception;
        }
        else
        {
            Node* parentNode = root->findNode(fatherId);
            if (parentNode == NULL)
            {
                exception = new wrongParentId();
                throw exception;
            }
            if (root->findNode(id) != NULL)
            {
                exception = new wrongNodeId();
                throw exception;
            }
            Operand* node = dynamic_cast<Operand*>(parentNode);
            if (node)
            {
                exception = new operandChild();
                throw exception;
            }
            parentNode->addNode(createNewOperator(id, fatherId, type));
        }
    }
    catch(Exception* exception)
    {
        exception->what();
        exit(FAIL);
    }
}
int Tree::evaluate_tree()
{
    try
    {
        return root->evaluateNode();
    }
    catch(Exception* exception)
    {
        exception->what();
        exit(FAIL);
    }
}