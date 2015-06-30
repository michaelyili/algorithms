#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
	stack<int> ints;
	stack<char> chs;
	int pos = 0;
	int postmp = pos;
	while (pos <= s.size()) {
		cout << "pos: " << pos << endl;
		int num = 0;
		char c = s[pos];
		if(c == '+' || c == '-' || c == '*' 
				|| c == '/' || pos == s.size())
		{
			num = atoi((const char*)s.substr(postmp, pos-postmp).c_str());
			
			if(!chs.empty() && chs.top() == '*') {
				int numtop = num*ints.top();
				ints.pop();
				ints.push(numtop);
				chs.pop();
			} else if(!chs.empty() && chs.top() == '/') {
				int numtop = ints.top() / num;
				ints.pop();
				ints.push(numtop);
				chs.pop();
			} else {
				ints.push(num);
			}
			if ( pos != s.size()) {
				chs.push(s[pos]);
				postmp = pos+1;
			}
		} else { }
		++pos;
	}

	int result = 0;
	while(!chs.empty()) {
		int num = ints.top();
		cout << "num: " << num << endl;
		cout << "ch: " << chs.top() << endl;
		ints.pop();
		if(chs.top() == '-') {
			num = num * (-1);
		}
		chs.pop();
		result += num;
	}
	result += ints.top();

	return result;
}

int main(int argc, char* argv[]) 
{
	string s = argv[1];
	cout << calculate(s) << endl;
	return 0;
}
