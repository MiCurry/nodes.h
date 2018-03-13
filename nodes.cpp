#include <unistd.h>
#include <iostream>
#include <set>

#include "nodes.h"

int main(int argv, char **argc) {

  Node Block("Block", "NULL");
  Node Pi("Float", "3.14");

  Node Block_2("Block", "3.13", &Pi, &Block);
  Block_2.printNode();

  Node Top("TOP", "NULL", &Block_2);
  Top.printNode();

  std::cout << "\n\nTree Traversal:" << std::endl;
  Top.traverseTree();

}
