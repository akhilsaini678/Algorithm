/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

int uniquePath1(int i,int j,int n,int m){
	if(i==n-1&&j==m-1) return 1;
	if(i>=n||j>=m) return 0;

	return uniquePath1(i+1,j,n,m) + uniquePath1(i,j+1,n,m);
}


int uniquePath2(vector<vector<int>> &dp,int i,int j,int n,int m){
	if(i==n-1&&j==m-1) return 1;
	if(i>=n||j>=m) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	return dp[i][j] = uniquePath2(dp,i+1,j,n,m) + uniquePath2(dp,i,j+1,n,m);
}

int uniquePath3(int x,int y){
	int ans = 1;
	int n = x+y-2;
	int r = y-1;
	for(int i=0;i<r;i++){
		ans = ans * (n-i);
		ans = ans / (i+1);
	}
	return ans;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> dp(n,vector<int> (m,-1));
	
	/* Approach 1:
		Traverse all the possibilities, using recursion.
		TC: O(2^(N+M)) SC: O(N+M)

	   Approach 2:
	 	Use dynamic programming.
	 	TC: O(N*M) SC: O(N*M)

	   Approach 3:
	   Each time, we are taking m+n-2 step to reach the end.
	   In this m+n-2 steps, we take m-1 down step and n-1 right step.
	   So bascially, out of m+n-2 steps, we need to select m-1 downward or n-1 rightward steps.
	   So selecting n-1 or m-1 from m+n-2 is our answer, i.e. (m+n-2)C(n-1) or (m+n-2)C(m-1)
	   TC: O(N-1) || O(M-1) SC: O(1)
	*/


	// int ans = uniquePath2(dp,0,0,n,m);
	int ans = uniquePath3(n,m);
	cout<<ans<<endl;
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
4 5


Output:
35

*/