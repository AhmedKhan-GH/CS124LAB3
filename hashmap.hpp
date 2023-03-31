#ifndef HASHMAP_HPP
#define HASHMAP_HPP
#include <utility>
#include <string>

const int HASH_SIZE = 32; // size of hashmap

// Node for sheparate chaining
struct ash_node {
    std::pair<char, std::string> data; // code is represented as a string of 1s and 0s
    hash_node* next = nullptr;
};

class hashmap
{
public:
    void insert(std::pair<char, std::string> data); // adds a new element to the hash map
    char find(std::string cipher) const; // finds the char that is represented by a given code

private:
    hash_node* table[HASH_SIZE];
    int hash(std::string cipher); // hash function
};

#endif //HASHMAP_HPP
