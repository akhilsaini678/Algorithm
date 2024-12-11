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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==NULL) return root;
	int currVal = root->val;
	int pVal = p->val, qVal = q->val;
	int low = min(pVal,qVal), high = max(pVal,qVal);
	if(currVal<low) return lowestCommonAncestor(root->right,p,q);
	else if(currVal>high) return lowestCommonAncestor(root->left,p,q);
	return root;
}


void solve()
{
	Node* root = new Node(10);
	root->left = new Node(7);
	root->right = new Node(15);
	root->left->left = new Node(3);
	root->left->right = new Node(8);
	root->right->left = new Node(12);
	root->right->right = new Node(18);
	cout<<lowestCommonAncestor(root,root->left,root->right)->val<<endl;
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


*/