/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,x,y;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	
	/* Brute force:
		Iterate the array from 0 to n-1, for each i, check if it is occuring twice. 
		TC: O(N*N) SC: O(1)

	   Another Solution 1:
	    Sort the array and then check the adjacent indexes.
	    TC: O(NLogN) SC: O(1)

	   Another Solution 2:
	   	Use a hashmap, and check which element occur twice.
	   	TC: O(N) SC: O(N)

	   Optimal Solution:
	   	1. In-place change: Run a for loop from 1 to n,
	   	2. Fast slow pointer:

	*/


	vector<pair<int,int>> ans;
	ans = mergeRanges(intervals);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
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