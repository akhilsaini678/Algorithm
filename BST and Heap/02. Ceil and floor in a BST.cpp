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

int floor(Node* root, int key){
	if(root==NULL) return INT_MIN;
	if(root->val<=key){
		return max(root->val,floor(root->right,key));
	}
	return floor(root->left,key);
}

int ceil(Node* root, int key){
	if(root==NULL) return INT_MAX;
	if(root->val>=key){
		return min(root->val,ceil(root->left,key));
	}
	return ceil(root->right,key);
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
	cout<<"Floor is: "<<floor(root,9)<<endl;
	cout<<"Ceil is: "<<ceil(root,9)<<endl;
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