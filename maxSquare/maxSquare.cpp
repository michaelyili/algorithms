/*
 * 输入矩阵只含有0和1，从中找出全部为1的最大矩阵
 *
 * */

#include <iostream>
#include <vector>
using namespace std;
#define MIN(x, y)	(x) < (y) ? (x) : (y)


int maximalSquare(vector<vector<char> >& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	int **dp = new int*[m];
	for(int i = 0; i < n; ++i) {
		dp[i] = new int[n];
	}
	int maxlen = 0;

	for(int y = 0; y < n; ++y) {
		for(int x = 0; x < m; ++x) {
			dp[x][y] = 0;

			if(x == 0 || y == 0) {
				dp[x][y] = 1;
			} else if(matrix[x][y] == '1') {
				dp[x][y] = 1;
			} 
			else {
				int tmp = MIN(dp[x-1][y], dp[x][y-1]);
				dp[x][y] = MIN(tmp, dp[x-1][y-1]) + 1;
				if(dp[x][y] > maxlen)
					maxlen = dp[x][y];
			}
		}
	}
	return maxlen;
}

int main(int argc, char *argv[]) {
	vector<char> a;
	vector<vector<char> >b;
	for(int i=0; i<3; ++i) {
		for(int j = 0; j<3; ++j) {
			int k;
			cin >> k;
			a.push_back(k);
		}
		b.push_back(a);
		a.clear();
	}
	for(int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j) 
		{
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}

	cout << endl;
	cout << maximalSquare(b) << endl;
	return 0;

}
