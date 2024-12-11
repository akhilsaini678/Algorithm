/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

pair<int,int> findRepeatedAndMissing(vector<int> &nums){
	int n = nums.size();
	int xorAll = 0;
	for(int i=0;i<n;i++){
		xorAll ^= nums[i];
		xorAll ^= (i+1);
	}
	int setBit = (xorAll & ~(xorAll-1));
	int setA = 0, setB = 0;
	for(int i=0;i<n;i++){
		(setBit & nums[i])? (setA ^= nums[i]): (setB ^= nums[i]);
		(setBit & (i+1))? (setA ^= (i+1)): (setB ^= (i+1)); 
	}
	for(int i=0;i<n;i++){
		if(setB==nums[i]){
			swap(setA,setB);
			break;
		}
	}
	return make_pair(setA,setB);
}

void solve()
{
	int n,x,y;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	
	/* Brute force:
		Iterate the array from 1 to n, for each i, check if it is occuring twice or is missing. 
		TC: O(N*N) SC: O(1)

	   Another Solution 1:
	    Sort the array and then check the adjacent indexes.
	    TC: O(NLogN) SC: O(1)

	   Another Solution 2:
	   	Use a hashmap, and check which element occur twice and which one is missing.
	   	TC: O(N) SC: O(N)

	   Optimal Solution:
	 	Take XOR of all the elements and 1 to N, together. Which will make sure that we have only
	 	xor of repeated and missing number.

	*/


	pair<int,int> ans = findRepeatedAndMissing(nums);
	cout<<ans.first<<" "<<ans.second<<endl;
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
5
3 1 2 5 3


Output:
3 4

*/