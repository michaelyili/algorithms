/*
 * find the k'th maximal element
 * we utilize quicksort algorithm, the time complexity if O(nlgn)
 * the parameter "k" from 0~m-1
 * that to say: when k==0, the returned value is the minimal value
 * and when k==1, the returned value is the second minimal value.
 * */

#include <iostream>
using namespace std;

template<typename T>
void myswap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
int partition(T *a, int left, int right, int k) {
	int lptr = left;
	int rptr = right-1;
	while(lptr <= rptr) {
		if(a[lptr] >= a[right] && a[rptr] < a[right]) {
			myswap(a[lptr], a[rptr]);
			++lptr;
			--rptr;
		} else {
			if(a[lptr] < a[right]) {
				++lptr;
			} else if(a[rptr] >= a[right]) {
				--rptr;
			}
		}
	}
	myswap(a[lptr], a[right]);
	return lptr;
}

template<typename T>
int findkmax_quicksort(T *a, int left, int right, int k) {
	if(left >= right) {
		cout << "left: " << left << "; "	\
			<< "right: " << right << endl;
		return a[left];
	}
	int lbase = left;
	int par = partition(a, left, right, k);
	cout << "par: " << par << endl;
	if(par == k)
		return a[par];
	else if (par > k)
		return findkmax_quicksort(a, left, par-1, k);
	else if(par < k) {
		cout << "par: " << par << "; " << "right: " << right << endl;
		return findkmax_quicksort(a, par+1, right, k);
	}
	return -1;
}

int main(int argc, char* argv[])
{
	int *a = new int[argc-1];
	for(int i=0; i<argc-1; ++i) {
		a[i] = atoi(argv[i+1]);
	}
	int k = 3;
	int re = findkmax_quicksort(a, 0, argc-2, k);
	cout << "result: " << re << endl;
	cout << "--------\n";
	for (int i=0; i<argc-1; ++i) {
		cout << a[i] << ", ";
	}
	cout << endl;

	return 0;
}
