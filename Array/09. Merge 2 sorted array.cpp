/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, vector<int> &nums2){
	int n = nums1.size(), m = nums2.size();
	int i = 0, j = 0, k = n-1;
	while(i<n){
		
	}
}

void solve()
{
	int n,x,y;
	cin>>n>>m;
	vector<int> nums1(n), nums2(m);
	for(int i=0;i<n;i++){
		cin>>nums1[i];
	}
	for(int i=0;i<m;i++){
		cin>>nums2[i];
	}
	
	/* Brute force:
		Iterate the first array and compare the first index of second array:
		If first[i] < second[0], then increment i.
		Else swap(first[i],second[0]), and then fix second[0] to it's right place.
		TC: O(N*M) SC: O(1)


		Another Solution:


	   Optimal Solution:
	 	Use merge sort to get the number of inversions for each sorted array
	 	TC: O(NlogN) SC: O(N)
	*/


	int ans = findInversion(nums,0,n-1);
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



Output:


*/