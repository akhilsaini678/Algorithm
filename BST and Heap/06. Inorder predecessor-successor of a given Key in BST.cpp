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

void inorder(Node* root, int &pre, int &succ,int key) {
    if(root==NULL) return;
	inorder(root->left,pre,succ,key);
	if(root->val<key){
    	pre = max(pre,root->val);
    }
	else if(root->val>key){
		succ = min(succ,root->val);
	}
	inorder(root->right,pre,succ,key);
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
	int pre = INT_MIN, succ = INT_MAX, key = 10;
	inorder(root,pre,succ,key);
	if(pre==INT_MIN) pre = -1;
	if(succ==INT_MAX) succ = -1;
	cout<<pre<<" "<<succ<<endl;
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