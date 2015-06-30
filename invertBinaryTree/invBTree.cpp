#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert (TreeNode* &root, int val) {
	TreeNode *p = root;
	TreeNode *newnode = new TreeNode(val);
	if (p == NULL) {
		root = newnode;
	} else {
		TreeNode *ptr = p;
		while( p != NULL) {
			ptr = p;
			if( p->val >= val ) {
				p = p->left;
			} else {
				p = p->right;
			}
		}
		if( ptr->val >= val ) {
			ptr->left = newnode;
		} else {
			ptr->right = newnode;
		}
	}
}

void createTree( TreeNode* &root, vector<int> a) {
	vector<int>::iterator it = a.begin();
	while(it != a.end()) {
		insert(root, *it);
		it++;
	}
}

void postOrder(TreeNode *root) {
	TreeNode* p = root;
	if( p == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << p->val << " ";
}

TreeNode* inverseBTree (TreeNode* &root) {
	TreeNode* p = root;
	if( p == NULL)
		return NULL;
	TreeNode* tmp = root->right;
	root->right = inverseBTree(root->left);
	root->left = inverseBTree(tmp);
	return root;
}

int main(int argc, char *argv[]) {
	vector<int> a;
//	string* s = new string[argc];
	for(int i=0; i<argc-1; ++i) {
		a.push_back(atoi( argv[i+1] ));
		cout << argv[i+1] << " ";
	}
	cout << endl;

	TreeNode *root = NULL;
	createTree( root, a );
	postOrder(root);
	cout << endl;
	
	inverseBTree(root);
	postOrder(root);
	cout << endl;

	return 0;
}
