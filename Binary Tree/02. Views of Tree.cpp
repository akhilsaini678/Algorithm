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

void printTree(vector<int> arr){
	for(auto val: arr) cout<<val<<" ";
	cout<<endl;
}

vector<int> leftView(Node* root){
	queue<Node*> q;
	q.push(root);
	vector<int> ans;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node* curr = q.front();
			q.pop();
			if(i==0) { ans.push_back(curr->val); }
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
		}
	}
	return ans;
}

vector<int> rightView(Node* root){
	queue<Node*> q;
	q.push(root);
	vector<int> ans;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node* curr = q.front();
			q.pop();
			if(i==size-1) { ans.push_back(curr->val); }
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
		}
	}
	return ans;
}

vector<int> topView(Node* root){
	queue<pair<Node*,int>> q;
	q.push({root,0});
	map<int,int> maps;
	vector<int> ans;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node* curr = q.front().first;
			int level = q.front().second;
			q.pop();
			if(maps.find(level)==maps.end()){
				maps[level] = curr->val;
			}
			if(curr->left!=NULL) q.push({curr->left,level-1});
			if(curr->right!=NULL) q.push({curr->right,level+1});
		}
	}
	for(auto it:maps){
		ans.push_back(it.second);
	}
	return ans;
}

vector<int> bottomView(Node* root){
	queue<pair<Node*,int>> q;
	q.push({root,0});
	map<int,int> maps;
	vector<int> ans;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node* curr = q.front().first;
			int level = q.front().second;
			q.pop();
			maps[level] = curr->val;
			if(curr->left!=NULL) q.push({curr->left,level-1});
			if(curr->right!=NULL) q.push({curr->right,level+1});
		}
	}
	for(auto it:maps){
		ans.push_back(it.second);
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