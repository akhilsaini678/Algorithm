/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node(int val){
		this->val = val;
		left = right = next = NULL;
	}
};


Node* populate(Node* root){
    if(root==NULL) return root;
	queue<Node*> q;
	q.push(root);
	Node* prev = NULL;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node* curr = q.front();
			q.pop();
			if(prev!=NULL) prev->next = curr;
            if(i==size-1) { curr->next = NULL; prev = NULL;}
            else prev = curr;
            			
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
		}
	}
	return root;
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
	cout<<"Left View  : "; printTree(leftView(root));
	cout<<"Right View : "; printTree(rightView(root));
	cout<<"Top View   : "; printTree(topView(root));
	cout<<"Bottom View: "; printTree(bottomView(root));
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
Left View  : 4 2 3 9 1 
Right View : 4 5 6 8 1 
Top View   : 3 2 4 5 6 
Bottom View: 1 9 7 8 6 

*/