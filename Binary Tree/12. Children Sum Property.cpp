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

void childrenSum(Node* root){
	if(root==NULL) return;
	int childSum = 0;
	if(root->left!=NULL) childSum+=root->left->val;
	if(root->right!=NULL) childSum+=root->right->val;

	if(childSum<root->val){
		if(root->left!=NULL) root->left->val = root->val;
		if(root->right!=NULL) root->right->val = root->val;
	}

	childrenSum(root->left);
	childrenSum(root->right);

	int tot = 0;
	if(root->left) tot+=root->left->val;
	if(root->right) tot+=root->right->val;
	if(root->left!=NULL || root->right!=NULL) root->val = tot;

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

	childrenSum(root);
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
5

*/