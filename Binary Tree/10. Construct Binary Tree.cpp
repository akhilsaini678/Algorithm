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


Node* constructTreePre(vector<int> &inorder,int inStart,int inEnd,vector<int> &preorder,int preStart, int preEnd,map<int,int> &maps){
	if(preStart>preEnd||inStart>inEnd) return NULL;
	Node* root = new Node(preorder[preStart]);
	int inRoot = maps[root->val];
	int numsLeft = inRoot - inStart;
	root->left = constructTreePre(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+numsLeft,maps);
	root->right = constructTreePre(inorder,inRoot+1,inEnd,preorder,preStart+numsLeft+1,preEnd,maps);
	return root;
}

Node* constructTreePost(vector<int> &inorder,int inStart,int inEnd,vector<int> &postorder,int postStart, int postEnd,map<int,int> &maps){
	if(postStart>postEnd||inStart>inEnd) return NULL;
	Node* root = new Node(postorder[postEnd]);
	int inRoot = maps[root->val];
	int numsLeft = inRoot - inStart;
	root->left = constructTreePost(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,maps);
	root->right = constructTreePost(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,maps);
	return root;
}


void solve()
{
	vector<int> inorder = {40, 20, 50, 10, 60, 30};
	vector<int> preorder = {10, 20, 40, 50, 30, 60};
	vector<int> postorder = {40, 50, 20, 60, 30, 10};
	map<int,int> maps;
	int n = inorder.size();
	for(int i=0;i<n;i++){
		maps[inorder[i]]=i;
	}
	Node* root1 = constructTreePre(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,maps);
	Node* root2 = constructTreePost(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,maps);
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