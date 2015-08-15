/*
 *	求子数组中最大的和
 *	子数组必须是连续的，例如：
 *	输入的数组为1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为3, 10, -4, 7, 2
 *	利用动态规划来求解
 * */

#include <iostream>

using namespace std;

// 求子数组的最大和
// 注意其中cursum用来记录子数组的和，如果出现子数组相加小于零，
// 则从该元素之后的位置重新记录
// curmax用来记录从0~i的元素间子数组的最大和
int maxSubSum(int *arr, int len) {
	int curmax = 0;
	int cursum = 0;

	for(int i=0; i<len; ++i) {
		int cursumtmp = cursum + arr[i];
		cursum = cursumtmp > 0 ? cursumtmp : 0;
		curmax = curmax > cursum ? curmax : cursum;
	}
	return curmax;
}

int main(int argc, char* argv[])
{
	int N;
	cin >> N;
	int *a = new int[N];
	for (int i=0; i<N; ++i) {
		cin >> a[i];
	}

	cout << maxSubSum(a, N) << endl;

	return 0;
}
