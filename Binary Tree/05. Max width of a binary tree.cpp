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


int maxWidth(Node* root){
	if(root==NULL) return 0;
	queue<pair<Node*,int>> q;
	q.push({root,0});
	int ans = 0;
	while(!q.empty()){
		int size = q.size();
		int left = 0, right = 0;
		for(int i=0;i<size;i++){
			Node* curr = q.front().first;
			int pos = q.front().second;
			q.pop();
			if(i==0) left = pos;
			if(i==size-1) right = pos;
			if(curr->left!=NULL) q.push({curr->left,2*pos+1});
			if(curr->right!=NULL) q.push({curr->right,2*pos+2});
		}
		ans = max(ans, right-left+1);
	}
	return ans;
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
	cout<<maxWidth(root)<<endl;
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