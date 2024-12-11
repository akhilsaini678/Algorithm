/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int value){
		data = value;
		next = NULL;
	}
};

void removeNthNode(Node* &head, int n){
	
	Node* tmp = new Node(-1);
	tmp->next = head;
	Node* fast = tmp;
	Node* slow = tmp;

	for(int i=0;i<n;i++){
		fast = fast->next;
	}
	while(fast->next!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	if(slow->data==-1){
		head = head->next;
		return;
	}
	Node* tmpDel = slow;
	tmpDel->next = tmpDel->next->next;
	// delete tmpDel;
}

void solve()
{
	int n,k;
	cin>>n;
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	removeNthNode(head,5);

	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
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



Output:


*/