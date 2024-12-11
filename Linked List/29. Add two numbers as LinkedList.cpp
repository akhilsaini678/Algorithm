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

Node* add(Node* &head1, Node* &head2){
	int carry = 0;
	int sum = 0;
	Node* head3 = NULL;
	Node* curr = head3;
	while(head1!=NULL||head2!=NULL){
		sum = (head1->data + head2->data + carry)%10;
		carry = (head1->data + head2->data + carry)/10;
		if(curr==NULL) curr = new Node()
		head1 = head1->next;
		head2 = head2->next;
	}
	while(head1!=NULL){

	}
	while(head2!=NULL){

	}
	if(carry!=0){

	}

	return head3;
}

void solve()
{
	int n,k;
	cin>>n;
	Node* head1 = new Node(1);
	head1->next = new Node(3);
	head1->next->next = new Node(5);
	head1->next->next->next = new Node(7);

	Node* head2 = new Node(2);
	head2->next = new Node(4);
	head2->next->next = new Node(6);
	head2->next->next->next = new Node(8);

	Node* head3 = add(head1,head2);
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