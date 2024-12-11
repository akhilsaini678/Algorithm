/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr){
	int n = arr.size();
	int low = 0, mid = 0;
	int high = n-1;
	while(mid<high){
		switch(arr[mid]){
			case 0: swap(arr[low],arr[mid]); low++, mid++;
			case 1: mid++;
			case 2: swap(arr[mid],arr[high]); high--;
		}
	}
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	// 1. Use sort() -  TC: O(NlogN) SC: O(1)
	// 2. Use counting sort - TC: O(2*N) SC: O(1)
	// 3. Use Dutch Flag Algorithm - TC: O(N) SC: O(1)
	sortArray(arr);
	
	for(auto it: arr){
		cout<<it<<" ";
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
1
6
2 0 2 1 1 0

Output:
0 0 1 1 2 2 

*/