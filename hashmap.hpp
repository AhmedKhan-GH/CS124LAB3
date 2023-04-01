#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include <utility>
#include <string>


class hashmap
{
public:

    // Node for sheparate chaining
    struct hash_node 
    {
        std::pair<char, std::string> data; 
        //pair of char, and cypher string key-value pairs
        hash_node* next = nullptr;
        //hash node is a linked list element
    };

    hashmap(); 
    //constructor to set consts
               
    void insert(std::pair<char, std::string> data); 
    // adds a new element to the hash map
    
    char find(std::string cipher) const; 
    // finds the char that is represented by a given code

    int hash(const std::string cipher) const;

private:
    const char nullchar;
    const int multiplier;
    const int table_size;
    
    hash_node* table[table_size];
    int hash(std::string cipher); // hash function
};

#endif //HASHMAP_HPP
