#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trie.h"


 int main(int argc,char **argv)
{
    // sanity check 
    if (argc != 1 )
    {
        printf("Usage: ./run\n");
        return 1;
    }
    
    // << main program >> // 
    Trie* head = calloc(1, sizeof(Trie));
    insert(head, "dog");
    insert(head, "do");
    
    if (search(head, "d"))
    {
        printf("it was found\n");
    }
    
    /// destroy 
    destroy(head);
    
    
    
    
    return 0;
}


// Method implementation 
Trie* insert(Trie* head, char* key)
{
    Trie* pointer = head; 
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        int index = tolower(key[i]) - 'a'; 
        if (pointer->next[index] == NULL)
        {
            pointer->next[index] = calloc(1, sizeof(Trie));
            pointer = pointer->next[index];
        }
        else 
        {
            pointer = pointer->next[index];
        }
    }
    pointer->word = true; 
    
    return head; 
    
}


bool search(Trie* head, char* key)
{
    // pointer to the head of the trie 
    Trie* pointer = head; 
    bool found = false; 
    
    for (int i = 0, n = strlen(key); i < n; i++) 
    {
        int index = tolower(key[i]) - 'a'; 
        if (pointer->next[index] == NULL)
        {
            return false;
        }
        pointer = pointer->next[index];
    }
    
    if (pointer->word == true)
    {
        found = true; 
    }
    
    return found; 
}

void destroy(Trie* head)
{
    if (head == NULL)
    {
        return; 
    }
    else 
    {
        for (int i = 0; i < EN_CHARACTERS; i++)
        {
            destroy(head->next[i]);
        }
        free(head);
    }
}

