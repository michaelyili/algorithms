#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Node {
	int val;
	int visited;
	Node* lp;
	Node* rp;
};

void insert(Node* &root, int val) {
	Node* p = root;

	Node* newnode = new Node;
	newnode->val = val;
	newnode->visited = 0;
	newnode->lp = NULL;
	newnode->rp = NULL;

	if(p == NULL) {
		root = newnode;
	} else {
		cout << "val: " << val << endl;
		Node* tmp;
		while( p != NULL) {
			tmp = p;
			if( p->val <= val ) {
				p = p->rp;
			} else {
				p = p->lp;
			}
		}
		if(tmp->val <= val) {
			tmp->rp = newnode;
		} else {
			tmp->lp = newnode;
		}
	}
}

void inOrder(Node* root) {
	Node* p = root;
	if(p == NULL) {
		return;
	} else {
		inOrder(p->lp);
		cout << p->val << endl;
		inOrder(p->rp);
	}
}

void createTree(Node* &root, vector<int> arr) {
	vector<int>::iterator it;
	it = arr.begin();
	while(it != arr.end()) {
		insert(root, *it);
		it++;
	}
}

int printLevel(Node* root, int level) {
	if( !root || level < 0) {
		return 0;
	}
	if(level == 0) {
		cout << root->val << " "; 
		return 1;
	}
	return printLevel(root->lp, level-1) + printLevel(root->rp, level-1);
}

// print data in every layer respectively
void printAllLevels(Node* root) {
	if(root == NULL) {
		return;
	} else {
		for(int level = 0; ; ++level) {
			if(! printLevel(root, level))
				break;
			cout << endl;
		}
	}
}

// preOrder
void preOrder(Node* root) {
	Node* p = root;
	stack<Node*> nodes;
	if(p == NULL) {
		return;
	} else {
		while( !nodes.empty() || p != NULL) {
			if( p != NULL ) {
				cout << p->val << endl;
				p->visited = 1;
				nodes.push(p);
				p = p->lp;
			} else {
				p = nodes.top();
				nodes.pop();
				p = p->rp;
			}
		}
	}
}

// callevel the layer number of the tree
// use postOrder traverse
int callevel (Node* root) {
	if(root == NULL)
		return 0;
	else {
		int cnt = 0;
		int ldepth = callevel(root->lp);
		if(ldepth > cnt)
			cnt = ldepth;
		int rdepth = callevel(root->rp);
		if(rdepth > cnt)
			cnt = rdepth;
		return ++cnt;
	}
}

int main(int argc, char* argv[]){
	int N;
	cin >> N;
	vector<int> arr;
	for(int i=0; i<N; ++i) {
		int k;
		cin >> k;
		arr.push_back(k);
	}

	Node* root = NULL;
	createTree(root, arr);
	inOrder(root);

	int level;
	cout << "please input the level you want to print: ";
	cin >> level;
	printLevel(root, level);
	cout << "\n";
	cout << "there are " <<callevel(root) << "layers in this tree.\n";
	cout << "print datas layer by layer.\n";
	printAllLevels(root);

	return 0;
}
