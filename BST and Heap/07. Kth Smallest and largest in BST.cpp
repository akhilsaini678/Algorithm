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



void smallest(Node* root, int &index, int k,int &ksmallest) {
	if(root==NULL) return;
	smallest(root->left,index,k,ksmallest);
	index++;
	if(index==k){
		ksmallest = root->val;
		return;
	}
	smallest(root->right,index,k,ksmallest);
}

void largest(Node* root, int &index, int k,int &klargest){
	if(root==NULL) return;
	largest(root->right,index,k,klargest);
	index++;
	if(index==k){
		klargest = root->val;
		return;
	}
	largest(root->left,index,k,klargest);
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
	
	int indexSmall = 0, indexlarge = 0;
	int ksmallest = 0, klargest = 0;
	smallest(root,indexSmall,3,ksmallest);
	largest(root,indexlarge,3,klargest);
	cout<<"Smallest: "<<ksmallest<<"\n";
	cout<<"Largest: "<<klargest<<endl;
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