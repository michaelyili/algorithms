#include <iostream>
#include <string>
using namespace std;

int nextindex(string patstr, int index) {
	int nextpos = 0;
	for(int k = 0; k < index; ++k) {
		string prefix;
		string postfix;

		prefix.assign((const char*)patstr.c_str(), 0, index-k);
		postfix.assign((const char*)patstr.c_str(), k+1, index-k);

		cout << prefix << ", " << postfix << endl;
		if(!strcmp((const char*)prefix.c_str(), 
					(const char*)postfix.c_str())) {
			nextpos = index-k;
			break;
		}
	}
	return nextpos;
}

int kmp(string src, string pattern) {
	int ptr = 0;
	int matchcnt = 0;
	while (ptr <= src.size() - pattern.size()) {
		if (pattern[0] != src[ptr]) {
			++ptr;
			continue;
		}
		int k = 1;
		while ( k < pattern.size() ) {
			if(pattern[k] != src[ptr+k]) {
				int nextp = nextindex(pattern, k-1);
				ptr += k - nextp;
				break;
			} else {
				++k;
			}
		//	cout << "k: " << k << endl;
		}
		if ( k == pattern.size() ) {
			++matchcnt;
			++ptr;
		}
		//cout << "ptr: " << ptr << endl;
	}
	return matchcnt;
}

int main(int argc, char* argv[]) {
	string src;
	string pattern;
	cin >> src >> pattern;

	cout << kmp(src, pattern) << endl;
	return 0;
}
