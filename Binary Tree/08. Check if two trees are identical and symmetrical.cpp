/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val){
		this->val = val;
		left = right =  NULL;
	}
};




bool isIdentical(Node* root1,Node* root2){
	if(root1==NULL||root2==NULL)
		return (root1==root2);

	return (root1->val==root2->val)&&isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right);
}

bool isSymmetric(Node* left, Node* right){
	if(left==NULL||right==NULL)
		return (left==right);

	return (left->val==right->val)&&isSymmetric(left->left,right->right)&&isSymmetric(left->right,right->left);
}

void mirrorTree(Node* root){
	if(root==NULL) return root;
	swap(root->left,root->right);
	mirrorTree(root->left);
	mirrorTree(root->right);
}


void solve()
{
	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(3);
	root->left->left->right = new Node(9);
	root->left->left->right->left = new Node(1);
	root->right->left = new Node(7);
	root->right->right = new Node(6);
	root->right->right->left = new Node(8);
	if(isIdentical(root,root)) cout<<"Tree is Identical"<<endl;
	else cout<<"Tree is not identical"<<endl;

	if(isSymmetric(root->left,root->right)) cout<<"Tree is symmetric."<<endl;
	else cout<<"Tree is not symmetric"<<endl;

	mirrorTree(root);
}




void fast()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("D:\\Data\\Online\\Coding\\Contest\\input.txt","r",stdin);
    freopen("D:\\Data\\Online\\Coding\\Contest\\output.txt","w",stdout);
    #endif
}

int32_t main()
{
    fast();
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}


/* Test Cases:

Input:
1


Output:
Tree is Identical
Tree is not symmetric

*/