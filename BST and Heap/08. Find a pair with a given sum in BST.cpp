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



bool isPair(Node* root, int sum, unordered_map<int,int> &maps) {
	if(root==NULL) return false;
	if(maps[sum-root->val]==1) return true;
	maps[root->val]=1; 
	if(isPair(root->left,sum,maps)||isPair(root->right,sum,maps)) return true;
	return false;
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
	
	unordered_map<int,int> maps;
	(isPair(root,18,maps))?cout<<"Pair Exists"<<endl: cout<<"Pair doesn't exists"<<endl;
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