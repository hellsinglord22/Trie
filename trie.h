

#ifndef TRIE_H
#define TRIE_H

// libraries to include 
#include <stdbool.h>

// Constant and data type 
#define EN_CHARACTERS 26

typedef struct trie 
{
    bool word;
    struct trie *next[EN_CHARACTERS]; 
}Trie; 

// Methods prototype 

/**
 * insert() - inserting a key into the trie data structure 
 * 
 * @param Trie* head - a pointer to the trie we want to manipulate 
 * @param char* key - the string we want to isnert into the trie
 * @return return Trie* -  head of the trie after insertion 
*/
Trie* insert(Trie* head, char* key);

/**
 * search() - search for a key in trie 
 * 
 * @param Trie* head - a pointer to the trie we want to seach within 
 * @param char* key - the string to search in the trie
 * @return bool - true if the key is found 
*/
bool search(Trie* head, char* key);

/**
 * destroy() - unload the trie from the memory
 * 
 * @param Trie* head - a pointer to the trie we want to unload
*/
void destroy(Trie* head);

#endif 