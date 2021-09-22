#include "node.hpp"

Node::Node(const size_t id, const size_t fatherId)
{
    nodeId = id;
    parentId = fatherId;
}
void Node::addNode(Node* newNode)
{
    connectedNodes.push_back(newNode);
}
Node* Node::findNode(size_t id)
{
    Node* temp;
    if (nodeId == id)
        return this;
    for (int i = 0; i < connectedNodes.size(); i++)
    {
        temp = connectedNodes[i]->findNode(id);
        if(temp != NULL)
            return temp;
    }
    return NULL;
}