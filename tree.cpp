#include "tree.hpp"

#include <string>
#include <utility>
#include <vector>
#include <iostream>

Node::Node() {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::~Node() {
    delete left;
    delete right;
}

void Node::add_node(Node* new_node) {
    if (new_node->data < data) {
        if (left == nullptr) { left = new_node; left->parent = this; }
        else { left->add_node(new_node); }
    }
    else {
        if (right == nullptr) { right = new_node; right->parent = this; }
        else { right->add_node(new_node); }
    }
}

void Node::set_left_child(Node* child)
{
   left = child;
   if (child != nullptr) { child->parent = this; }
}

void Node::set_right_child(Node* child)
{
   right = child;
   if (child != nullptr) { child->parent = this; }
}

void Node::print(int depth) {
    std::string spaces = "";
    for (int i = 0; i < depth; i++) { spaces += ' '; }

    std::cout << spaces << "(" << data.first << " - " << data.second << ") " << std::endl;

    if (left != nullptr) { left->print(depth + 1); }
    if (right != nullptr) { right->print(depth + 1); }
}

Tree::Tree() {
    root = nullptr;
}

Tree::Tree(std::vector<std::pair<char, std::string> > data) : Tree() {
    for (auto element : data)
    {
        this->insert(element);
    }
}

Tree::~Tree() {
    delete root;
}

void Tree::insert(std::pair<char, std::string> element)
{
   Node* new_node = new Node;
   new_node->data = element;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) { root = new_node; }
   else { root->add_node(new_node); }
   fix_after_add(new_node);
}

std::string Tree::find(char element) const {
    Node* current = root;
    while (current != nullptr) {
        char current_ele = current->data.first;
        if (element == current_ele) { return current->data.second; }
        else if (element < current_ele) { current = current->left; }
        else { current = current->right; }
    }

    // element was not found
    return "";
}

void Tree::replace_with(Node* to_be_replaced, Node* replacement)
{
   if (to_be_replaced->parent == nullptr)
   {
      replacement->parent = nullptr;
      root = replacement;
   }
   else if (to_be_replaced == to_be_replaced->parent->left)
   {
      to_be_replaced->parent->set_left_child(replacement);
   }
   else
   {
      to_be_replaced->parent->set_right_child(replacement);
   }
}

void Tree::fix_after_add(Node* new_node)
{
   if (new_node->parent == nullptr)
   {
      new_node->color = BLACK;
   }
   else
   {
      new_node->color = RED;
      if (new_node->parent->color == RED) { fix_double_red(new_node); }
   }
}

void Tree::fix_double_red(Node* child)
{
   Node* parent = child->parent;
   Node* grandparent = parent->parent;
   if (grandparent == nullptr) { parent->color = BLACK; return; }
   Node* n1;
   Node* n2;
   Node* n3;
   Node* t1;
   Node* t2;
   Node* t3;
   Node* t4;
   if (parent == grandparent->left)
   {
      n3 = grandparent; t4 = grandparent->right;
      if (child == parent->left)
      {
         n1 = child; n2 = parent;
         t1 = child->left; t2 = child->right; t3 = parent->right;
      }
      else
      {
         n1 = parent; n2 = child;
         t1 = parent->left; t2 = child->left; t3 = child->right;
      }
   }
   else
   {
      n1 = grandparent; t1 = grandparent->left;
      if (child == parent->left)
      {
         n2 = child; n3 = parent;
         t2 = child->left; t3 = child->right; t4 = parent->right;
      }
      else
      {
         n2 = parent; n3 = child;
         t2 = parent->left; t3 = child->left; t4 = child->right;
      }
   }

   replace_with(grandparent, n2);
   n1->set_left_child(t1);
   n1->set_right_child(t2);
   n2->set_left_child(n1);
   n2->set_right_child(n3);
   n3->set_left_child(t3);
   n3->set_right_child(t4);
   n2->color = grandparent->color - 1;
   n1->color = BLACK;
   n3->color = BLACK;

   if (n2 == root)
   {
      root->color = BLACK;
   }
   else if (n2->color == RED && n2->parent->color == RED)
   {
      fix_double_red(n2);
   }
}

void Tree::erase(std::pair<char, std::string> element)
{
   // Find node to be removed

   Node* to_be_removed = root;
   bool found = false;
   while (!found && to_be_removed != nullptr)
   {
      if (element == to_be_removed->data)
      {
         found = true;
      }
      else if (element < to_be_removed->data)
      {
         to_be_removed = to_be_removed->left;
      }
      else
      {
         to_be_removed = to_be_removed->right;
      }
   }

   if (!found) { return; }

   // to_be_removedcontains element

   // If one of the children is empty, use the other

   if (to_be_removed->left == nullptr || to_be_removed->right == nullptr)
   {
      Node* new_child;
      if (to_be_removed->left == nullptr) { new_child = to_be_removed->right; }
      else { new_child = to_be_removed->left; }

      fix_before_remove(to_be_removed);
      replace_with(to_be_removed, new_child);
      return;
   }

   // Neither subtree is empty

   // Find smallest element of the right subtree

   Node* smallest = to_be_removed->right;
   while (smallest->left != nullptr)
   {
      smallest = smallest->left;
   }

   // smallestcontains smallest child in right subtree

   // Move contents, unlink child

   to_be_removed->data = smallest->data;
   fix_before_remove(smallest);
   replace_with(smallest, smallest->right);
}

void Tree::fix_before_remove(Node* to_be_removed)
{
   if (to_be_removed->color == RED) { return; }

   if (to_be_removed->left != nullptr
         || to_be_removed->right != nullptr) // It is not a leaf
   {
      // Color the child black
      if (to_be_removed->left == nullptr) { to_be_removed->right->color = BLACK; }
      else { to_be_removed->left->color = BLACK; }
   }
   else {bubble_up(to_be_removed->parent); }
}

void Tree::bubble_up(Node* parent)
{
   if (parent == nullptr) { return; }
   parent->color++;
   parent->left->color--;
   parent->right->color--;

   if (bubble_up_fix(parent->left)) { return; }
   if (bubble_up_fix(parent->right)) { return; }

   if (parent->color == DOUBLE_BLACK)
   {
      if (parent->parent == nullptr) { parent->color = BLACK; }
      else { bubble_up(parent->parent); }
   }
}

bool Tree::bubble_up_fix(Node* child)
{
   if (child->color == NEGATIVE_RED)
   {
      fix_negative_red(child);
      return true;
   }
   else if (child->color == RED)
   {
      if (child->left != nullptr && child->left->color == RED)
      {
         fix_double_red(child->left); return true;
      }
      if (child->right != nullptr && child->right->color == RED)
      {
         fix_double_red(child->right); return true;
      }
   }
   return false;
}

void Tree::fix_negative_red(Node* neg_red)
{
   Node* parent = neg_red->parent;
   Node* child;
   if (parent->left == neg_red)
   {
      Node* n1 = neg_red->left;
      Node* n2 = neg_red;
      Node* n3 = neg_red->right;
      Node* n4 = parent;
      Node* t1 = n3->left;
      Node* t2 = n3->right;
      Node* t3 = n4->right;
      n1->color = RED;
      n2->color = BLACK;
      n4->color = BLACK;

      replace_with(n4, n3);
      n3->set_left_child(n2);
      n3->set_right_child(n4);
      n2->set_left_child(n1);
      n2->set_right_child(t1);
      n4->set_left_child(t2);
      n4->set_right_child(t3);

      child = n1;
   }
   else // Mirror image
   {
      Node* n4 = neg_red->right;
      Node* n3 = neg_red;
      Node* n2 = neg_red->left;
      Node* n1 = parent;
      Node* t3 = n2->right;
      Node* t2 = n2->left;
      Node* t1 = n1->left;
      n4->color = RED;
      n3->color = BLACK;
      n1->color = BLACK;

      replace_with(n1, n2);
      n2->set_right_child(n3);
      n2->set_left_child(n1);
      n3->set_right_child(n4);
      n3->set_left_child(t3);
      n1->set_right_child(t2);
      n1->set_left_child(t1);

      child = n4;
   }

   if (child->left != nullptr && child->left->color == RED)
   {
      fix_double_red(child->left);
   }
   else if (child->right != nullptr && child->right->color == RED)
   {
      fix_double_red(child->right);
   }
}

void Tree::print() {
    root->print(0);
}
