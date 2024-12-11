/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void getNextPermutation(vector<int> &arr){
	int n = arr.size();
	int index = -1;
	for(int i=n-2;i>=0;i--){
		if(arr[i]<arr[i+1]){
			index = i;
			break;
		}
	}

	if(index == -1){
		reverse(arr.begin(),arr.end());
		return;
	}
	for(int i=n-1;i>=index;i--){
		if(arr[i]>arr[index]){
			swap(arr[i],arr[index]);
			break;
		}
	}
	reverse(arr.begin()+index+1,arr.end());
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	/* Use Brute force:
		Get all the permutation and search for the input, print the next one to it.
		TC: O(N! * N) SC: O(1)
	*/

	/* 
		Use C++ next_permutation function
	*/

	/* Optimal:
		1. Find the first element such that arr[index]<arr[index+1]
		2. Swap it with the first bigger element from the end. (That bigger element will have it's own permutations now)
		3. Reverse the array from index + 1 to n - 1. 
	*/
	getNextPermutation(arr);
	for(auto it:arr){
		cout<<it<<" ";
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
1
6
7 1 5 6 4 3

Output:
7 1 6 3 4 5 

*/