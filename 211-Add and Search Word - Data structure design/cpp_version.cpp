//
// Created by VicChan on 2017/4/4.
//
#include <string.h>
#include <iostream>
#include <cstdlib>

using std::string;

typedef struct node {
    char character;
    int counter;
    struct node* sub_nodes[26];
} Node;



class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->start = (Node*)malloc(sizeof(Node));
        for(int i = 0; i < 26; i++) {
            this->start->sub_nodes[i] = NULL;
        }
        this->start = 0;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        string::iterator iter = word.begin();
        string::iterator end = word.end();
        struct node* current = this->start;
        while(iter != end) {
            int index = hash(*iter);
            if (!current->sub_nodes[index]) {
                struct node* newNode = (struct node*)malloc(sizeof(struct node));
                current->sub_nodes[index] = newNode;
                newNode->counter = 0;
                newNode->character = *iter;
                for(int i = 0; i < 26; i ++)
                    newNode->sub_nodes[i] = NULL;
            }
            current = current->sub_nodes[index];
            iter ++;
        }
        current->counter += 1;

    }

    int hash(char c) {
        return c-'a';
    }

    bool cosearch(struct node* root, string::iterator iter, string::iterator end) {
        bool flag = false;
        if (*iter == '.') {
            for(int i = 0; i < 26; i ++) {
                if(root->sub_nodes[i]) {
                    if (iter+1 == end) {
                        if(root->sub_nodes[i]->counter) {
                            return true;
                        }
                    } else {
                        flag = cosearch(root->sub_nodes[i], iter+1, end);
                        if (flag)
                            return true;
                    }
                }
            }
            return false;
        } else {
            return searchFunc(root, iter, end);
        }
    }

    bool searchFunc(struct node* head, string::iterator start, string::iterator end) {
        string::iterator iter = start;
        struct node* current = head;
        while (iter != end) {
            if (*iter == '.') {
                return cosearch(current, iter, end);
            } else {
                int index = hash(*iter);
                current = current->sub_nodes[index];
                if(!current)
                    break;
            }
            iter ++;
        }
        if(iter != end)
            return false;
        if(iter == end &&  current->counter > 0)
            return true;
        return false;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchFunc(start, word.begin(), word.end());
    }

private:
    struct node* start;
};


