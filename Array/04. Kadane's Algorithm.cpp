/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum1(vector<int> &arr){
	int n = arr.size();
	int maxSum = INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum = 0;
			for(int k=i;k<=j;k++){
				sum+=arr[k];
			}
			maxSum = max(maxSum,sum);
		}
	}
	return maxSum;
}

int maxSubarraySum2(vector<int> &arr){
	int n = arr.size();
	int maxSum = INT_MIN;
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			maxSum = max(maxSum,sum);
		}
	}
	return maxSum;
}


int maxSubarraySum3(vector<int> &arr){
	int n = arr.size();
	int currSum = 0;
	int maxSum = INT_MIN;
	for(int i=0;i<n;i++){
		currSum += arr[i];
		maxSum = max(maxSum,currSum);
		if(currSum<0) currSum = 0; 
	}
	return maxSum;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	int maxSum = 0;
	
	// T.C: O(N*N*N) and S.C: O(1)
	maxSum = maxSubarraySum1(arr);
	// T.C: O(N*N) and S.C: O(1)
	maxSum = maxSubarraySum2(arr);
	// T.C: O(N) and S.C: O(1)
	maxSum = maxSubarraySum3(arr);
	cout<<maxSum<<endl;
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
6 2

Output:
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
15

*/