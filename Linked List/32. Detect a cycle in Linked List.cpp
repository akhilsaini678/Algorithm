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

void deleteNode(Node* node){
	if(node->next==NULL){
		node = NULL;
		return;
	}
	node->data = node->next->data;
	node->next = node->next->next;
}

bool findCycle(Node* head){
	if(head->next==NULL) return false;
	Node* slow = head;
	Node* fast = head;
	do {
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast) return true;	
	} while(fast!=NULL&&fast->next!=NULL);
	return false;
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
	head->next->next->next->next->next = head->next->next;
	/*
		Approach 1: Hashing
		TC: O(N) SC: O(1)

		Approach 2: Tortoise and Hare Algorithm
		TC: O(N) SC: O(1)

	*/
	if(findCycle(head)) cout<<"Found Cycle"<<endl;
	else cout<<"Cycle is not found"<<endl;
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