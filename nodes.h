#ifndef NODES_H_INCLUDE
#define NODES_H_INCLUDE

/* nodes.h - Miles A. Curry - March 2018
 * A generic tree data structure deisnged to hold an AST and produce graphvis
 * png of itself.
 *
 * See constructors and node.h for examples on creating a node with children.
 * Children can be inserted at the time of the nodes creation with the
 * construtor or afterwards with the addChild() call.
 */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include <sstream>
#include <set>
#include <string>


class Node { /* Our AST Data Structure */
  public:
    static int id_num;
    std::string name;
    std::string id;
    std::string value;

    std::set<class Node> children;

    /* Overlad comparator operator to include the value stored in our node */
    friend bool operator< (const Node &left, const Node &right) { return left.id < right.id; }

    /* Constructors */
    Node( ){ name="NULL"; value="NULL";}
    Node(const char *category, std::string *associated_value){
      name = std::string(category);
      value = *associated_value;
      initNodeID(name);
    }
    Node(const char *category, const char *associated_value, Node *child1){
      name = std::string(category);
      value = std::string(associated_value);
      initNodeID(name);

      addChild(*child1);
    }
    Node(const char *category, const char *associated_value, Node *child1, Node *child2){
      name = std::string(category);
      value = std::string(associated_value);
      initNodeID(name);

      addChild(*child1);
      addChild(*child2);
    }
    Node(const char *category, const char *associated_value, Node *child1, Node *child2, Node *child3){
      name = std::string(category);
      value = std::string(associated_value);
      initNodeID(name);

      addChild(*child1);
      addChild(*child2);
      addChild(*child3);
    }
    Node(const char *category, const char *associated_value, Node *child1, Node *child2, Node *child3, Node *child4){
      name = std::string(category);
      value = std::string(associated_value);
      initNodeID(name);

      addChild(*child1);
      addChild(*child2);
      addChild(*child3);
      addChild(*child4);
    }
    Node(const char *category, const char *associated_value, Node *child1, Node *child2, Node *child3, Node *child4,
                               Node *child5){
      name = std::string(category);
      value = std::string(associated_value);
      initNodeID(name);

      addChild(*child1);
      addChild(*child2);
      addChild(*child3);
      addChild(*child4);
      addChild(*child5);
    }
    Node(const char *category, const char *associated_value, Node *child1, Node *child2, Node *child3, Node *child4, Node *child5, Node *child6){
      name = std::string(category);
      value = std::string(associated_value);

      initNodeID(name);

      addChild(*child1);
      addChild(*child2);
      addChild(*child3);
      addChild(*child4);
      addChild(*child5);
      addChild(*child6);
    }

    Node(std::string category, std::string associated_value){
      name = category;
      value = associated_value;
      initNodeID(name);
    }
    Node(std::string category, std::string associated_value, Node *child1){
      name = category;
      value = associated_value;
      initNodeID(name);

      addChild(*child1);
    }
    Node(std::string *category, std::string *associated_value, Node *child1, Node *child2){
      name = *category;
      value = *associated_value;
      initNodeID(name);

      addChild(*child1);
      addChild(*child2);
    }
    Node(std::string *category, std::string *associated_value, Node *child1, Node *child2, Node *child3){
      name = *category;
      value = *associated_value;
      initNodeID(name);

      addChild(*child1);
      addChild(*child2);
      addChild(*child3);
    }

    void addChild(Node node){
      if( node.name != "NULL")
        children.insert(node);
      }

    void printNode() const{
      std::cout << "ID: " << id << std::endl;
      std::cout << " Name: " << name << std::endl;
      std::cout << " Value: " << value << std::endl;
      std::cout << " Num Children: " << children.size() << std::endl;
      if ( children.size() > 0 ){ // Print Children
        std::cout << "\tChildren: " << std::endl;
        for (std::set<class Node>::iterator it=children.begin(); it!=children.end(); ++it){
               std::cout << "child: " << it->id << std::endl;
        }
      }
    }

    void traverseTree() const{
      this->createGraphVisConnection();
      /* printNode(); std::cout << "\n"; */
      if (children.size() > 0){
        for (std::set<class Node>::iterator it=children.begin(); it!=children.end(); ++it){
          it->traverseTree();
        }
      }
    }
    void printChildren() const{
      if (children.size() > 0){
        std::cout << "Num Children = " << children.size() << "Children: " << std::endl;
        for (std::set<class Node>::iterator it=children.begin(); it!=children.end(); ++it){
          std::cout << "\tname: "<< it->name << " id: " << it->id << std::endl;
        }
      }else
        std::cout << "No Children" << std::endl;


    }

  private:
    void initNodeID(std::string name){
      if (name == "NULL"){
          return;
      }
      std::ostringstream s;
      s << id_num; id_num++;
      id = s.str();
      id.insert(0, name);
      return;
    }

    void createGraphVisConnection() const{
        if (value != "NULL")
          std::cout << id << " [shape=box,label=\"" << name << ": " << value << "\"];" << std::endl;
        else
          std::cout << id << " [label=\"" << name << "\"];"<< std::endl;

        if (children.size() > 0){
          for (std::set<class Node>::iterator it=children.begin(); it!=children.end(); ++it){
            std::cout << id << "->" << it->id << ";" << std::endl;
          }
        }

    }
};

int Node::id_num = 0;


#endif
