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


int height(Node* root){
	if(root==NULL) return 0;
	return 1 + max(height(root->left),height(root->right));
}

int diameter(Node* root, int &ans){
	
	if(root==NULL) return 0;
	int lh = diameter(root->left,ans);
	int rh = diameter(root->right,ans);
	
	ans = max(ans,1+lh+rh);
	return 1 + max(lh,rh);
}

int maxSumPath(Node* root,int &ans){

	if(root==NULL) return 0;
	int left = max(0,maxSumPath(root->left,ans));
	int right = max(0,maxSumPath(root->right,ans));

	ans = max(ans,root->val+left+right);
	return root->val + max(left,right);

}

int isBalanced(Node* root){
	
	if(root==NULL) return 0;
	int lh = isBalanced(root->left);
	if(lh==-1) return -1;
	int rh = isBalanced(root->right);
	if(rh==-1) return -1;
	
	if(abs(lh-rh)>1) return -1;
	return 1+max(lh,rh);
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
		All these 4 problems have same pattern.
		That during a recursive call, when we are coming up, for each curr_root
		we have value for left and right subtree. So, for each curr_root, we can 
		decide what decision to take.

		In height: For every curr_root, we have what is the max left height and
		what is the max right height, so we can take max of any of these.

		In diameter: For every curr_root, we know what is the max number of node(basically max height)
		in left or right, so we can take left + right + 1

		In case of balanced tree, same thing we have height details for each curr_root,

		In case of max path sum, it is also the same pattern as diameter, it's just that 
		instead of taking number of nodes, we are taking values of nodes, so we know what
		max values we have in left and right, so we can always take left+right+curr.
		One edge case is: If left or right return negative value, then we don't need to take,
		since it will just decrease our answer.
		
	*/
	cout<<"Height: "<<height(root)<<endl;
	int ans = 0;
	int balanceTree = isBalanced(root);
	diameter(root,ans);
	cout<<"Diameter: "<<ans<<endl;
	if(balanceTree==-1) cout<<"Not Balanced"<<endl; else cout<<"Balanced"<<endl;

	ans = INT_MIN;
	maxSumPath(root,ans);
	cout<<"Max Sum Path: "<<ans<<endl;
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
Height: 5
Diameter: 8
Not Balanced

*/