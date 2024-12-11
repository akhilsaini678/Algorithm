/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	node* next;
	node(int val){
		this.val = val;
		next = NULL;
	}
};

void reverse(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	while(curr!=NULL){
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

void solve()
{
	
	int n,k;
	cin>>n;
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next->next = new Node(3);
	head->next->next->next->next = new Node(4);
	head->next->next->next->next->next = new Node(5);

	reverse(head);
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