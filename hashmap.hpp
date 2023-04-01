#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include <utility>
#include <string>

int hash(std::string cipher); // hash function

// Node for sheparate chaining
struct hash_node {
    std::pair<char, std::string> data; // code is represented as a string of 1s and 0s
    hash_node* next = nullptr;
};

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
    const int TABLE_SIZE = 32; // size of hashmap
    const char NULLCHAR = '\0';
    hash_node* table[HASH_SIZE];
};

#endif //HASHMAP_HPP
