#include <iostream>

#include <stack>

using std::string;
using std::stack;





class Solution {
public:
	struct Value{
		int current;
		int increment;
		Value(int cur, int inc):current(cur),increment(inc){}
	};
	char toChar(int b){
		switch(b){
			case 0:
				return '0';
			case 1:
				return '1';
			default:
				return '0';
		}
	}

	string addBinary(string a, string b){
		string long_str = a.size() > b.size()?a:b;
		string short_str = a.size()>b.size()?b:a;
		stack<int > char_num;
		int short_cur = (int)short_str.size()-1;
		int long_cur = (int)long_str.size()-1;
		int increment = 0;

		while(short_cur >=0){
			Value value = calculate(long_str[long_cur],short_str[short_cur],increment);
			char_num.push(value.current);
			increment = value.increment;
			long_cur --;
			short_cur --;
		}
		while(long_cur >= 0) {
			Value value = calculate(long_str[long_cur],'0',increment);
			char_num.push(value.current);
			increment = value.increment;
			long_cur --;
		}
		string result;
		if(increment == 1){
			char_num.push(1);
		}
		while(char_num.size() > 0){
			result.push_back(toChar(char_num.top()));
			char_num.pop();
		}
		return result;
	}
	Value calculate(char a, char b, int increment){
		int aVal = a == '0'?0:1;
		int bVal = b == '0'?0:1;
		int res = aVal + bVal + increment;
		switch(res){
			case 0:return Value(0,0);
			case 1:return Value(1,0);
			case 2:return Value(0,1);
			case 3:return Value(1,1);
			default:
				break;
		}
		return Value(0,0);
	}


	/*
    string addBinary(string a, string b) {
		string result;
		if(a.size() == 0 && b.size() == 0)
			return "0";
		if(a.size() ==0 || b.size() != 0){
			return b;
		}
		if(a.size() != 0 || b.size() == 0){
			return a;
		}

		int size = (int)(a.size()<b.size()?a.size():b.size());
		Value value = calculate(a[0],b[0],0);
		int i = 1;
		while(i<size){
			result.push_back(toChar(value.current));
			value = calculate(a[i],b[i],value.increment);
			i ++;
		}

		while(i < a.size()) {
			value = calculate('0',a[i],value.increment);
			result.push_back(toChar(value.current));
			i ++;
		}

		while (i < b.size()){
			value = calculate('0',a[i],value.increment);
			result.push_back(toChar(value.current));
			i ++;
		}
		return  result;
    }

	char toChar(int b){
		switch(b){
			case 0:
				return '0';
			case 1:
				return '1';
			default:
				return '0';
		}
	}

	Value calculate(char a, char b, int increment){
		int aVal = a == '0'?0:1;
		int bVal = b == '0'?0:1;
		int res = a + b + increment;
		switch(res){
			case 0:return Value(0,0);
			case 1:return Value(1,0);
			case 2:return Value(1,1);
			default:
				break;
		}
		return Value(0,0);
	}
	*/


};



int main() {
	string a = "11";
	string b = "1";
	Solution sol;
	std::cout<<sol.addBinary(a,b)<<std::endl;


	return 0;
}