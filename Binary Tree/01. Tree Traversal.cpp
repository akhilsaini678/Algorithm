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

void inOrder(Node* root){
	if(root!=NULL){
		inOrder(root->left);
		cout<<(root->val)<<" ";
		inOrder(root->right);
	}
}

void inOrderIter(Node* root){
	if(root==NULL) return;
	stack<Node*> st;
	Node* curr = root;
	while(!st.empty() || curr!=NULL){
		while(curr!=NULL){
			st.push(curr);
			curr = curr->left;
		}
		Node* tmp = st.top();
		st.pop();
		cout<<tmp->val<<" ";
		curr = tmp->right;
	}
}


void preOrder(Node* root){
	if(root!=NULL){
		cout<<(root->val)<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void preOrderIter(Node* root){
	if(root==NULL) return;
	stack<Node*> st;
	Node* curr = root;
	while(!st.empty() || curr!=NULL){
		while(curr!=NULL){
			cout<<curr->val<<" ";
			st.push(curr);
			curr = curr->left;
		}
		Node* tmp = st.top();
		st.pop();
		curr = tmp->right;
	}
}


void postOrder(Node* root){
	if(root!=NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<(root->val)<<" ";
	}
}

void postOrderIter(Node* root){

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
	cout<<"Inorder (rec) : ";inOrder(root);
	cout<<endl;
	cout<<"Inorder (ite) : ";inOrderIter(root);
	cout<<endl;
	cout<<"Preorder (rec) : ";preOrder(root);
	cout<<endl;
	cout<<"Preorder (ite) : ";preOrderIter(root);
	cout<<endl;
	cout<<"Postorder (rec) : ";postOrder(root);
	cout<<endl;
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