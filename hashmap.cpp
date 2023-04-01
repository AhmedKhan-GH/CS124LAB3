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
<<<<<<< HEAD
    int index = hash(data.second);
    hash_node* new_node = new hash_node;
=======
    int index = hash(data.second) % table_size;
    hash_node* new_node = new Hash_node;
>>>>>>> 9c2150b51ec0cb95d640befe8f1a64cf3c082d7d
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
