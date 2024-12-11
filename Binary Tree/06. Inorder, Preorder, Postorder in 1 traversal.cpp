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


void traverse(Node* root){
	stack<pair<Node*,int>> st;
	st.push({root,1});
	vector<int> pre, in, post;
	while(!st.empty()){
		Node* curr = st.top().first;
		int seq = st.top().second;
		st.pop();
		switch(seq){
		case 1:
			pre.push_back(curr->val);
			st.push({curr,seq+1});
			if(curr->left!=NULL) st.push({curr->left,1});
			break;
		case 2:
			in.push_back(curr->val);
			st.push({curr,seq+1});
			if(curr->right!=NULL) st.push({curr->right,1});
			break;
		case 3:
			post.push_back(curr->val);
		}
	}
	for(auto val:pre) cout<<val<<" ";
	cout<<endl;
	for(auto val:in) cout<<val<<" ";
	cout<<endl;
	for(auto val:post) cout<<val<<" ";
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
	traverse(root);
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
4 2 3 9 1 5 7 6 8 
3 1 9 2 4 7 5 8 6 
1 9 3 2 7 8 6 5 4 

*/