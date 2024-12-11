/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;


struct TrieNode {
	TrieNode* child[26];
	bool isEnd;
	TrieNode(){
		isEnd = false;
		for(int i=0;i<26;i++){
			child[i] = NULL;
		}
	}
};


void insert(TrieNode* root, string str){

	TrieNode* curr = root;
	for(int i=0;i<str.length();i++){
		int index = str[i]-'a';
		if(curr->child[index]==NULL){
			curr->child[index] = new TrieNode();
		}
		curr = curr->child[index];
	}
	curr->isEnd = true;
}

bool search(TrieNode* root, string str){

	TrieNode* curr = root;
	for(int i=0;i<str.length();i++){
		int index = str[i]-'a';
		if(curr->child[index]==NULL){
			return false;
		}
		curr = curr->child[index];
	}
	return curr->isEnd;
}

bool isEmpty(TrieNode* root){

	for(int i=0;i<26;i++){
		if(root->child[i]!=NULL) return false;
	}
	return true;
}

TrieNode* deletes(TrieNode* root, string &str, int i){
	if(root==NULL) return root;
	if(i==str.length()){
		root->isEnd = false;
		if(isEmpty(root)){
			delete(root);
			root = NULL;
		}
		return root;
	}
	int index = str[i]-'a';
	root->child[index] = deletes(root->child[index],str,i+1);
	if(isEmpty(root)&&root->isEnd==false){
		delete(root);
		root = NULL;
	}
	return root;
}


void solve()
{
	int n;
	cin>>n;
	vector<string> str_arr(n);
	TrieNode *root = new TrieNode();
	for(int i=0;i<n;i++)
	{
		cin>>str_arr[i];
		insert(root,str_arr[i]);
	}

	string forsearch="geek";
	string check="";
	check = (search(root,forsearch))?"Present":"Not Present";
	cout<<check<<endl;

	deletes(root,forsearch,0);

	check = (search(root,forsearch))?"Present":"Not Present";
	cout<<check<<endl;
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
6
akh
nav
geek
mil
ton
base


Output:
Present
Not Present

*/