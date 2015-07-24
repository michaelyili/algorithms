/*
 * quicksort algorithm
 * two main steps: partition, and then recurse
 * */

#include <iostream>
using namespace std;

template <typename T>
void myswap(T &a, T &b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int partition(int *a, int left, int right) {
	int lptr = left;
	int rptr = right-1;

	while(lptr <= rptr) {	
		// NOTE: in order to completely compare all 
		// the numbers, the condition is "<=", not "<"
		if(a[lptr] >= a[right] && a[rptr] < a[right]) {
			myswap(a[lptr], a[rptr]);
			++lptr;
			--rptr;
			cout << "lp: " << lptr << "; rp: " << rptr << endl;
		} else {
			if(a[lptr] < a[right]) {
				++lptr;
			} else if(a[rptr] >= a[right]) {
				--rptr;
			}
		}
	}
	// alfer one scan operation, we should swap the 
	// current element with reference number
	myswap(a[lptr], a[right]);
	return lptr;
}

void quicksort(int* a, int left, int right) {
	if(left >= right)
		return;
	else {
		int pos = partition(a, left, right);
		quicksort(a, left, pos-1);
		quicksort(a, pos+1, right);
	}
}

int main(int argc, char* argv[])
{
	cout << "argc: " << argc << endl;
	int *a = new int[argc-1];
	for(int i = 0; i < argc-1; ++i) {
		a[i] = atoi(argv[i+1]);
	}
	quicksort(a, 0, argc-2);

	for(int i=0; i< argc-1; ++i) {
		cout << a[i] <<" ";
	}
	cout << endl;

	delete a;
	return 0;
}
