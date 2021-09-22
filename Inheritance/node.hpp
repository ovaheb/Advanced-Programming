#ifndef __NODE_H__
#define __NODE_H__

#include "libraries.hpp"
#include "exception.hpp"

class Node
{
public:
    Node(const size_t id, const size_t fatherId);
    void addNode(Node* newNode);
    Node* findNode(size_t id);
    virtual int evaluateNode() = 0;
protected:
    size_t nodeId;
    size_t parentId;
    vector<Node*> connectedNodes;
};

#endif