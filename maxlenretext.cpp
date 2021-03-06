/*
 * 求一个字符串中子串最长回文长度：例如12421就是一个回文
 *
 * 解法：遍历字符串数组，从1开始，以遍历到的字符作为中心，匹配两边的字符
 * 同时为了保证奇数和偶数处理都能成功，可以在每个字符间插入一个特殊字符，
 * 那么对字符串的处理实际上就都一样了，只是在最终返回长度的时候需要注意去掉
 * 加入的字符的个数
 * Date: 2015.07.08
 * */

#include<iostream>
using namespace std;


bool doseend(char c) {
	if((c >= 'a' && c <= 'z') || c == '*')
		return false;
	else return true;
}

int maxretext(char* s) {
	int len = 0;
	int i=0;
	while( !doseend(s[i]) ) {
		i++;
		int lentmp = 0;
		for(int j=i-1; j>=0; j--) {
			if(s[j] == s[2*i-j] && !doseend(s[2*i-j-1])) {
				lentmp++;
			} else{
				break;
			}
		}
		if(lentmp > len) {
			len = lentmp;
		}
	}

	return len + 1;
}

char* preprostr(char* s, int n) {
	char* str = new char[n+n-1];
	int i = 0;
	while((s[i] <= 'z' && s[i] >= 'a') || s[i] == '*')
	{
		int odd = 2*i+1;
		int eve = 2*i;
		str[eve] = s[i];
		if(i < n-1)
			str[odd] = '*';
		++i;
	}
	return str;
}

int main() {

	int N;
	scanf("%d", &N);

	char **s = new char*[N];
	for(int i=0; i<N; i++) {
		s[i] = new char[1000000];
		scanf("%s", s[i]);
		int len = 0;
		while(s[i][len] != '\0') {
			++len;
		}
		char *str = preprostr(s[i], len);
		printf("%d\n", maxretext(str));
	}
	//for(int i=0; i<N; i++) {
	//	printf("%d\n", maxretext(s[i]));
	//}

	return 0;
}
