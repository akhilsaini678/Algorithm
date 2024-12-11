/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(vector<int> &arr){
	unordered_map<int,int> maps;
	int sum = 0, ans = 0, n = arr.size();
	for(int i=0;i<n;i++){
		maps[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		if(maps.find(arr[i]+1)==maps.end()){
			int j = 0;
			while(maps[arr[i]-j]==1){
				j++;
			}
			ans = max(ans, j);
		}
	}
	return ans;
}


void solve()
{
	
	int n,k;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	

	/* Approach 1: Brute Force
		Iterate the array from 0 to n-1, for each index, how many elements of
		TC: O(N^2) SC: O(1)

	   Approach 2: Sorting
	   	Sort the array and check for consecutive windows, and take the maximum out of it.
	   	TC: O(NLogN) SC: O(1)

	   Approach 3:
	   	Traverse the array and insert all the values into a map.
	   	Then iterate the array and check if this is the last element of the consecutive subsequence.
	   	If it is the last element, then check how many lower elements are there.
	   	And take the maximum out of it. In  this way, we will be traversing the array only once.
	   	TC: O(N) SC: O(N)
		
	*/

	cout<<longestConsecutiveSubsequence(arr)<<endl;
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
100 200 1 3 2 4


Output:
4

*/