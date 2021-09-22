#include "tree.hpp"
#include "libraries.hpp"

int main() 
{
  Tree t;
  t.add_operator_node(1, DUMMY_ROOT, Add);
  t.add_operator_node(2, 1, Multiply);
  t.add_operand_node(3, 1, 5);
  t.add_operand_node(4, 2, 2);
  t.add_operand_node(5, 2, 3);
  int result = t.evaluate_tree();
  cout << result << endl;
}