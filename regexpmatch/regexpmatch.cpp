/*
 *'.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false      
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * */


#include <iostream>
using namespace std;

bool isMatch(const char *srcstr, const char *regstr) {
	if(srcstr == NULL || regstr == NULL)
		return false;
	if(*regstr == '\0')
		return *srcstr == '\0';
	else {
		if(*(regstr+1) == '*') {
			if((*srcstr != '\0' && *regstr == '.') || *regstr == *srcstr) {
				if(isMatch(srcstr, regstr+2))
					return true;
				return isMatch(++srcstr, regstr);
			} else {
				return isMatch(srcstr, regstr+2);
			}
		} else {
			if((*srcstr !='\0' && *regstr == '.') || *srcstr == *regstr) {
				return isMatch(++srcstr, ++regstr);
			}
		}
		return false;
	}
}

int main(int argc, char *argv[]) {
	char *src = argv[1];
	char *reg = argv[2];
	cout << src << endl;
	cout << reg << endl;
	cout << isMatch(src, reg) << endl;
	return 0;
}
