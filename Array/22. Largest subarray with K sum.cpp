/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

int largestSubarrayWithK(vector<int> &arr, int k){
	unordered_map<int,int> maps;
	int sum = 0, ans = 0;
	for(int i=0;i<arr.size();i++){
		sum+=arr[i];
		if(maps.find(sum+k)!=maps.end())
			ans = max(ans, i - maps[sum]);
		else
			maps[sum] = i;
	}
	return ans;
}


void solve()
{
	
	int n,k;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>k;


	/* Approach 1: Brute Force
		Get all the subarrays and find out the maximum length subarray with sum k.
		TC: O(N^2) SC: O(1)

	   Approach 2: Hashing
	   	While iterating subarray keep on storing the sum till so far into the hashmap.
	   	If the same sum has been seen before also, then it means we have a subarray from
	   	that index to till now and so on.
	    TC: O(N) SC: O(N)
		
	*/

	cout<<largestSubarrayWithK(arr,k)<<endl;

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
9 -3 3 -1 6 -5
0


Output:
5

*/