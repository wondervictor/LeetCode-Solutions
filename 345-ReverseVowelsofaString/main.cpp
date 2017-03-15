#include <iostream>
#include <stack>
#include <queue>

/**
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".

 * */

using std::stack;
using std::string;

using std::cout;
using std::queue;


class Solution {
public:
    string reverseVowels(string s) {
		string result;

        stack<char>	vowels;
		queue<int> 	index;
		for(int i = 0; i < s.size(); i ++) {
			if(isVowel(s[i])) {
				vowels.push(s[i]);
				index.push(i);
			}
		}
		while(!index.empty()){
			int i = index.front();
			index.pop();
			s[i] = vowels.top();
			vowels.pop();
		}


		/*
		for(auto i : s){
			if(isVowel(i)) {
				vowels.push(i);
			}
		}

		int i = 0;
		for (;i < s.size();i ++) {
			if(isVowel(s[i])) {
				result.push_back(vowels.top());
				vowels.pop();
			} else {
				result.push_back(s[i]);
			}
		}
		*/
		return s;
    }

	bool isVowel(char s){
		char i = tolower(s);

		if(i == 'a'||i =='e'||i =='i'||i == 'o'||i == 'u') {
			return true;
		} else {
			return false;
		}
	}

};


int main() {

	Solution sol;
	cout<<sol.reverseVowels("HeLLO");



	return 0;
}