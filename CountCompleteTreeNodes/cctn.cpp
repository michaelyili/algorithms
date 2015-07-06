#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// create a complete tree
void insertCompleteTree(TreeNode* &root, int val) {
	TreeNode* p = root;
	TreeNode* node = new TreeNode(val);
	if(p == NULL) {
		root = node;
	} else {
		if(p->left == NULL ) {
			insertCompleteTree(root->left, val);
		} else {
			if( p->right == NULL) {
				insertCompleteTree(root->right, val);
			} else {
				insertCompleteTree(root->left, val);
			}
		}
	}
}

/*void createCompleteTree(TreeNode* &root, vector<int> num)
{
	if(num.size() == 0)
		return;
	for(int i=0; i<num.size(); ++i) {
		TreeNode* node = new TreeNode(num[i]);


	}
}
*/
int N = 0;
int countNodes(TreeNode *root) {
	int count = 0;
	if(root == NULL) {
		return 0;
	} else {
		count = count + countNodes(root->left);
		count = count + countNodes(root->right);
		return count + 1;
	}
}

void inOrder(TreeNode* root) {
	TreeNode* p = root;
	if( p == NULL ) 
		return;
	inOrder(p->left);
	cout << p->val << " ";
	inOrder(p->right);
}

void preOrder(TreeNode* root) {
	TreeNode* p = root;
	if( p== NULL )
		return;
	cout << p->val<< " ";
	preOrder(p->left);
	preOrder(p->right);
}

int main(int argc, char* argv[])
{
	TreeNode* root = NULL;
	for(int i=0; i<argc-1; ++i) {
		int num = atoi(argv[i+1]);
		insertCompleteTree(root, num);
	}
	inOrder(root);
	cout << endl;
	preOrder(root);
	cout << endl;

	cout << "totle nodes: " << countNodes(root) << endl;

	return 0;
}
