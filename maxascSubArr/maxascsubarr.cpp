/*
 * 求数列中最长单调递增子序列
 * */

#include <iostream>
using namespace std;

int length(char *a, char &endele, int index) {
	int len = 0;
	if(index < 2) {
		len = 1;
		endele = a[0]; 
		if (index = 1) {
			endele = a[0] > a[1] ? a[0] : a[1];
		}
		return 1;
	}

	if(a[index])


	return 0;
}

int main(int argv, char* argv[]) 
{
	return 0;
}
