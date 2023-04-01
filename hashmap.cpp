#include "hashmap.hpp"
#include <utility>
#include <stdexcept>
#include <string>

// hash function
int hash(std::string cipher) {
    int result = 0;
    int multiplier = 1;
    for (char c : cipher) {
        if (c == '1') { result += multiplier; }

        // error handling
        else if (c != '0') {
            throw std::invalid_argument("Cipher includes chars other than 1 or 0");
        }

        // double the value of the next digit
        multiplier *= 2;
    }

    // fit to hash size
    result %= HASH_SIZE;
    return result;
}

// adds a new element to the hash map
void hashmap::insert(std::pair<char, std::string> data) {
    int index = hash(data.second);
    hash_node* new_node = new hash_node;
    new_node->data = data;
    new_node->next = table[index];
    table[index] = new_node;
}

// finds the char that is represented by a given code
char hashmap::find(std::string cipher) const {
    int index = hash(cipher);
    hash_node* current = table[index];
    while (current != nullptr) {
        if (current->data.second == cipher) { return current->data.first; }
        current = current->next;
    }

    return NOT_FOUND; // failed to find char
}
