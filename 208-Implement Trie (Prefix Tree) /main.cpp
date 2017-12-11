#include <iostream>
#include <map>

using namespace std;


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        nodes = new map<char, node*>();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        map<char, node*>* currentMap = nodes;
        node* currentNode = nullptr;
        for(auto c: word) {
            if ((*currentMap)[c]) {
                currentNode = (*currentMap)[c];
                currentMap = currentNode->subNodes;
            } else {
                node* newNode = new node(c);
                (*currentMap)[c] = newNode;
                currentMap = newNode->subNodes;
                currentNode = newNode;
            }
        }
        currentNode->hasWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        map<char, node*>* currentMap = nodes;
        node* currentNode = nullptr;
        for(auto c: word) {
            if ((*currentMap)[c]) {
                currentNode = (*currentMap)[c];
                currentMap = currentNode->subNodes;
            } else {
                return false;
            }
        }
        return currentNode->hasWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        map<char, node*>* currentMap = nodes;
        for(auto c: prefix) {
            if ((*currentMap)[c]) {
                node* currentNode = (*currentMap)[c];
                currentMap = currentNode->subNodes;
            } else {
                return false;
            }
        }
        return true;
    }
private:

    struct node {
        char character;
        bool hasWord;
        map<char, node*>* subNodes;
        node(char c):character(c){
            hasWord = false;
            subNodes = new map<char, node*>();
        }
    };
    map<char, node*>* nodes;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {

    Trie obj;
    obj.insert("word");
    obj.insert("astron");
    cout<<obj.search("astron");

    return 0;
}