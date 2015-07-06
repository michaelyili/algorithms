#include <iostream>
#include <vector>
using namespace std;

/* 求最最大子串，该函数返回一个最大子串串数组，其中元素
 * num[i]的含义是包含当前元素的最大子串的数值
 * */
int *maxsubarr(vector<int> num) {
	int len = num.size();
	int *subarr = new int[len];
	subarr[0] = num[0];
	for(int i=1; i<len; ++i) {
		subarr[i] = subarr[i-1] > 0 ? (subarr[i-1]+num[i]) : num[i];
	}
	return subarr;
}

int main() {
	int arr[] = {-1,-2,1,4,-2,1};
	vector<int> a(arr, arr+6);
	for (int i=0; i<a.size(); ++i) {
		cout << a[i] << " "; 
	}
	cout << endl;

	int *b = new int[a.size()];
	b = maxsubarr(a);
	for (int i=0; i<a.size(); ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}
