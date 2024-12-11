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


Node* lca(Node* root,int val1,int val2){
	
	if(root==NULL||root->val==val1||root->val==val2) return root;
	Node* left = lca(root->left,val1,val2);
	Node* right = lca(root->right,val1,val2);
	if(left==NULL) return right;
	else if(right==NULL) return left;
	return root;
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

	/*
		Approach: It is a very simple problem
		While iterating, whenever we found the matching value, it means it is either in left or right.
		So, we return this value, so at any curr node, whenever we will have a value coming from both left
		and right, it means that this curr node is the LCA, since it has both the values in it's left and
		right, if it doesn't have the both the value, then it might be in other left or right.
	*/

	Node* ans = lca(root,7,8);
	cout<<ans->val<<endl;	
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