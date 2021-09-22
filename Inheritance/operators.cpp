#include "operators.hpp"

void checkInputsNumber(int maximumInputsAvailable, int inputsConnected)
{
    if (inputsConnected != maximumInputsAvailable)
    {
        Exception* exception = new invalidTreeStructure();
        throw exception;
    }
}

Operator::Operator(const size_t id, const size_t fatherId)
	: Node(id, fatherId) {}

Sum::Sum(const size_t id, const size_t fatherId)
    : Operator(id, fatherId) {}
int Sum::evaluateNode()
{
    checkInputsNumber(MAXIMUM_NODES_ATTACHED_TO_SUM, connectedNodes.size());
    int value = 0;
    for (int i = 0; i < connectedNodes.size(); i++)
        value = value + connectedNodes[i]->evaluateNode();
    return value;
}

Mult::Mult(const size_t id, const size_t fatherId)
    : Operator(id, fatherId) {}
int Mult::evaluateNode()
{
    checkInputsNumber(MAXIMUM_NODES_ATTACHED_TO_MULT, connectedNodes.size());
    int value = 1;
    for (int i = 0; i < connectedNodes.size(); i++)
        value = value * connectedNodes[i]->evaluateNode();
    return value;
}

Negative::Negative(const size_t id, const size_t fatherId)
    : Operator(id, fatherId) {}
int Negative::evaluateNode()
{
    checkInputsNumber(MAXIMUM_NODES_ATTACHED_TO_NEGATIVE, connectedNodes.size());
    return connectedNodes[0]->evaluateNode() * (-1);
}

Med::Med(const size_t id, const size_t parentId)
    : Operator(id, parentId) {}
int Med::evaluateNode()
{
    vector<int> medNodes;
    for (int i = 0; i < connectedNodes.size(); i++){
        medNodes.push_back(connectedNodes[i]->evaluateNode());
    }
    sort(medNodes.begin(), medNodes.end());
    if (medNodes.size() % 2 == 0)
        return (medNodes[medNodes.size() / 2 - 1] + medNodes[medNodes.size() / 2]) / 2;
    else
        return medNodes[medNodes.size() / 2];
}