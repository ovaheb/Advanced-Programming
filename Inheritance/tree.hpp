#ifndef __TREE_H__
#define __TREE_H__

#include "libraries.hpp"
#include "node.hpp"
#include "operators.hpp"
#include "operand.hpp"

class Tree
{
public:
  Tree();
  void add_operand_node(const std::size_t id, const std::size_t parent_id, const int value);
  void add_operator_node(const std::size_t id, const std::size_t parent_id, const OperatorType type);
  Node* createNewOperator(const size_t id, const size_t fatherId, const OperatorType type);
  int evaluate_tree();
private:
  Node* root;
};

#endif