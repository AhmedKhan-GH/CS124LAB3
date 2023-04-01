#include "hashmap.hpp"
#include <utility>
#include <stdexcept>
#include <string>

hashmap::hashmap() : table_size(32), multiplier(31), nullchar('\0');

// hash function
int hashmap::hash(std::string cipher) const
{
	int hashed_value = 0;
    for (char c : cipher)
    {
        hash_value = hash_value * multiplier + (int)c;
    }

    return hashed_value;
}

// adds a new element to the hash map
void hashmap::insert(std::pair<char, std::string> data) {
    int index = hash(data.second) % table_size;
    hash_node* new_node = new Hash_node;
    new_node->data = data;
    new_node->next = table[index];
    table[index] = new_node;
}

// finds the char that is represented by a given code
char hashmap::find(std::string cipher) const {
    int index = hash(cipher) % table_size;
    hash_node* current = table[index];
    while (current != nullptr) 
    {
        if (current->data.second == cipher) 
        { 
            return current->data.first; 
        }
        current = current->next;
    }

    return nullchar; // failed to find char
}
