/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(vector<int> &arr){
	int maxProfit = 0;
	int minSoFar = arr[0];
	for(auto stockPrice: arr){
		minSoFar = min(minSoFar, stockPrice);
		maxProfit = max(maxProfit, stockPrice - minSoFar);
	}
	return maxProfit;
}


void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	/* Use Brute force:
		Run two nested loop, for i, 0 to n-1 and for j, i+1 to n-1
		Consider each ith day as buy day and each jth day as sell and get maxProfit.
		TC: O(N*N) SC: O(1)
	*/

	/* Optimal:
		While traversing keep a track of minmum stock price so far.
		And keep on calculating maxProfit from that minimum price.
	*/
	int maxProfit = 0;
	maxProfit = getMaxProfit(arr);
	
	cout<<maxProfit<<endl;
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
7 1 5 3 6 4

Output:
5

*/