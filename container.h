#ifndef CONTAINER_H
#define CONTAINER_H

//map for container children
#include <map>

//string for container names
#include <string>

//iostream for cerr and console applications
#include <iostream>

//list for creating path objects that can be returned
#include <list>

//external int that all implementation classes refer to for assigning unique itegers to objects
extern int ledger;

class Container;
class Path;

class Path
{
public:
    Path();
    /*!
        @brief creates a doubly linked list for a path of any particular node
        @param node takes a node to be the end of the path and work backwards to root node
    */
    void append(Container* node);
    
    void print();
private:

    /// @brief doubly linked list of container pointers to be a sequential representative of a container path in the tree
    std::list<Container*> nodes;
};

class Container
{
public:
    /*! 
        @brief overloaded constructor for creation of a container node
        @param name the name of the container
        @param parent the pointer to the parent container, nullptr if root node
    */ 
    Container(std::string name);

    /// @brief container class destructor that calls destructor for all descendant nodes
    ~Container();

    /// @brief returns the id integer of the respective node
    int get_id() const;

    /// @brief returns the name string of the respective node
    std::string get_name() const;

    /*!
        @brief called every time an object is parsed from a csv, keeping 
        ledger to be one more than the current max in the dataset
        @param update the value of the current parsed index to be passed to the external int
    */ 
    static void update_ledger(int update);
    
    /// @brief increases the ledger by one, to be called every time a new container object is created
    static void iterate_ledger();

    /*!
        @brief operation to assign a container node 'subject" as a child of another container node 'target
        or return a false bool and cerr to console if attempting an illegal operation such as: nesting a node 
        or within itself nesting a node within one of its own descendants
        @param node a pointer to the subject node which is intended to be nested with its target
    */
    bool nest(Container* node);

    /// @brief wrapper function to call recursive helper tree print function and decide on root title
    void print_tree();

    Path get_path();
private:

    /*!
        @brief internal recursive helper function that actually prints tree elements and calls itself
        iterated over the children of the given element
        @param depth an integer parameter that determines the number of indentations, creating the
        tree architecture in the console
    */
    void _print_tree(int depth);

    /// @brief a unique integer identifier for map tree reconstruction from CSV
    const int id;

    /// @brief a string identifier for tree view
    std::string name;

    /// @brief pointer to the parent container
    Container* parent;

    /// @brief map of child container pointers retrievable with id's or iteratable (for tree view)
    std::map<int, Container*> children;
};


#endif //CONTAINER_H