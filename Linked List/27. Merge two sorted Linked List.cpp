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

Node* merge(Node* &head1, Node* &head2){

	if(head1->data>head2->data) swap(head1,head2);
	Node* curr1 = head1;
	Node* curr2 = head2;
	while(curr1!=NULL && curr2!=NULL){
		Node* tmp;
		while(curr1!= NULL && curr1->data<curr2->data){
			tmp = curr1;
			curr1 = curr1->next;
		}
		tmp->next = curr2;
		swap(curr1,curr2);
	}
	return head1;
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

	Node* head3 = merge(head1,head2);
	
	while(head3!=NULL){
		cout<<head3->data<<" ";
		head3 = head3->next;
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