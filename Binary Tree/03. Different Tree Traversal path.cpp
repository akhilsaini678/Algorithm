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

struct data {
	Node* node;
	int level;
	int pos;
};

void printTree(vector<int> arr){
	for(auto ele: arr) cout<<ele<<" ";
	cout<<endl;
}

void printTree2d(vector<vector<int>> arr){
	for(auto row: arr){
		for(auto ele: row){
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}

vector<vector<int>> zigZagTraversal(Node* root){
	queue<Node*> q;
	q.push(root);
	vector<vector<int>> ans;
	bool flag = 1;
	while(!q.empty()){
		int size = q.size();
		vector<int> row;
		for(int i=0;i<size;i++){
			Node* curr = q.front();
			q.pop();
			row.push_back(curr->val);
			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);
		}
		if(flag==0) reverse(row.begin(),row.end());
		ans.push_back(row);
		flag = 1 - flag;
	}
	return ans;
}

vector<vector<int>> verticalTraversal(Node* root){
	queue<struct data> q;
	q.push({root,0,0});
	map<int,vector<pair<int,int>>> maps;
	vector<vector<int>> ans;
	int level = 0;
	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node* curr = q.front().node;
			int pos = q.front().pos;
			q.pop();
			maps[pos].push_back({level,curr->val});
			if(curr->left!=NULL) q.push({curr->left,level,pos-1});
			if(curr->right!=NULL) q.push({curr->right,level,pos+1});
		}
		level++;
	}
	for(auto row:maps){
		sort(row.second.begin(),row.second.end());
		vector<int> tmp;
		for(auto ele:row.second){
			tmp.push_back(ele.second);
		}
		ans.push_back(tmp);
	}
	return ans;
}





void leafView(Node* root,vector<int> &leaf){
	if(root!=NULL){
		leafView(root->left,leaf);
		if(root->left==NULL&&root->right==NULL) leaf.push_back(root->val);
		leafView(root->right,leaf);
	}
}

void leftView(Node* root,vector<int> &left){
	if(root!=NULL){
		if(root->left==NULL&&root->right==NULL) return;
		left.push_back(root->val);
		if(root->left!=NULL) leftView(root->left,left);
		else if(root->right!=NULL) leftView(root->right,left);
	}
}

void rightView(Node* root,vector<int> &right){
	if(root!=NULL){
		if(root->left==NULL&&root->right==NULL) return;
		right.push_back(root->val);
		if(root->right!=NULL) rightView(root->right,right);
		else if(root->left!=NULL) rightView(root->left,right);
	}
}

vector<int> boundaryTraversal(Node* root){
	queue<Node*> q;
	q.push(root);
	vector<int> left, right, leaf, ans;
	leafView(root,leaf);
	leftView(root,left);
	rightView(root,right);
	reverse(right.begin(),right.end());
	right.pop_back();
	for(auto it: left) ans.push_back(it);
	for(auto it: leaf) ans.push_back(it);
	for(auto it: right) ans.push_back(it);
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
	cout<<"Zig Zag Traversal  :\n"; printTree2d(zigZagTraversal(root));
	cout<<"Vertical Traversal :\n"; printTree2d(verticalTraversal(root));
	cout<<"Boundary Traversal :\n"; printTree(boundaryTraversal(root));
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
Zig Zag Traversal  :
4 
5 2 
3 7 6 
8 9 
1 
Vertical Traversal :
3 1 
2 9 
4 7 
5 8 
6 
Boundary Traversal :
4 2 3 9 1 7 8 6 5 

*/