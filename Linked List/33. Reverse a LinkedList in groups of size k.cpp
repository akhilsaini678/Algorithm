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

Node* reverseLinkedList(Node* &head,int k){
	Node* prev = NULL;
	Node* curr = head;
	int count = 0;
	Node* prevCheck = NULL;
	while(curr!=NULL){
		Node* start = curr;
		while(count%k!=0||curr!=NULL){
			Node* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		prev->next = prevCheck;
		prevCheck = curr;
	}
	return head;
}

void solve()
{
	int n,k;
	cin>>k;
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	
	/*
		Approach 1: Hashing
		TC: O(N) SC: O(1)

		Approach 2: Tortoise and Hare Algorithm
		TC: O(N) SC: O(1)

	*/
	
	reverseLinkedList(head,k);
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
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



Output:


*/