#ifndef TREE_HPP
#define TREE_HPP

#include <string>
#include <utility>
#include <vector>

/*
 * Red Black Tree implementation altered from textbook version
*/

const int BLACK = 1;
const int RED = 0;
const int NEGATIVE_RED = -1;
const int DOUBLE_BLACK = 2;

class Node
{
public:
   Node();
   ~Node();
private:
   void add_node(Node* new_node);
   void set_left_child(Node* child);
   void set_right_child(Node* child);
   std::pair<char, std::string> data;
   void print(int depth);
   Node* left;
   Node* right;
   Node* parent;
   int color;
friend class Tree;
};

class Tree
{
public:
    Tree();
    Tree(std::vector<std::pair<char, std::string>> data);
    ~Tree();
    void insert(std::pair<char, std::string> data);
    void erase(std::pair<char, std::string> data);
    void print();
private:
    Node* root;

    void replace_with(Node* to_be_replaced, Node* replacement);
    void fix_after_add(Node* new_node);
    void fix_double_red(Node* child);
    void fix_before_remove(Node* to_be_removed);
    void bubble_up(Node* parent);
    bool bubble_up_fix(Node* child);
    void fix_negative_red(Node* neg_red);
};

#endif //TREE_HPP
