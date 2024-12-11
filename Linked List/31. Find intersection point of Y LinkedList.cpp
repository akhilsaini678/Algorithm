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

Node* findIntersection(Node* head1, Node* head2){
	Node* d1 = head1;
	Node* d2 = head2;
	while(d1!=d2){
		d1 = (d1==NULL)?head2:d1->next;
		d2 = (d2==NULL)?head1:d2->next;
	}
	return d1;
}

void solve()
{
	Node* head1 = new Node(9);
	head1->next = new Node(7);
	Node* head2 = new Node(1);
	head2->next = new Node(2);
	head2->next->next = new Node(3);
	head2->next->next->next = new Node(4);
	head2->next->next->next->next = new Node(5);
	head1->next = head2->next->next->next;

	/* Approach 1: Brute Force
		Iterate one linked list and while iterating check for each node in the other list
		If it matches the current node or not.
		TC: O(N*M) S.C: O(1)

	   Approach 2: Hashing
		Iterate and store nodes of 1 linked list in hashmap, and while iterating check for
		the nodes of other linked list if it exists in hashmap or not.
		TC: O(N) S.C: O(N)

	   Approach 3: Greedy
	   	Iterate both the linked list and find the absolute difference of length of both. 
	   	And traverse that diff for the longer linked list, after that traverse both at the
	   	same time and check.
	   	TC: O(3*N) S.C: O(1)

	   Approch 4: Optimised
	   	Iterate both the linked list if null is found set the head to the opposite linked list
	   	In this way, both the pointer will traverse both linked list once, and in the second
	   	iteration both the pointers will be going simulateneously.
	   	TC: O(2*N) S.C: O(1)

	*/


	Node* ans = findIntersection(head1,head2);
	cout<<ans->data<<endl;
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