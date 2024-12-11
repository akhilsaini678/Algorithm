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

bool search(Node* root, int key){
	if(root==NULL) return false;
	if(root->val>key) return search(root->left,key);
	else if(root->val<key) return search(root->right,key);
	return true;
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

	if(search(root,14)) cout<<"Found"<<endl; else cout<<"Not Found"<<endl;
	//insert(root,11);
	//del(root,11);
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
Inorder (rec) : 3 1 9 2 4 7 5 8 6 
Inorder (ite) : 3 1 9 2 4 7 5 8 6 
Preorder (rec) : 4 2 3 9 1 5 7 6 8 
Preorder (ite) : 4 2 3 9 1 5 7 6 8 
Postorder (rec) : 1 9 3 2 7 8 6 5 4 

*/