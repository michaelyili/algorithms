#include<iostream>
#include<list>
using namespace std;

// Note: iterator does not overload the operator '+' or '-', if you want
// to change the pointer 'it', you can use '++' and '--'

void delMidNode(list<int> &a, int n) {
	list<int>::iterator it = a.begin();
	list<int>::iterator it2 = it;
	for(int i=0; i<n; ++i) {
		it++;
		it2++;
	}
	it2++;

	swap(*it, *it2);
	a.erase(it2++);
	
}

int main(int argc, char *argv[]) 
{
	list<int> a(4,0);
	list<int>::iterator it = a.begin();
	int i=0;
	while(it != a.end()) {
		*it = i;
		i++;
		it++;
	}

	delMidNode(a, 1);
	it = a.begin();
	while(it != a.end()) {
		cout<< *it << endl;
		it++;
	}
	
	return 0;
}
