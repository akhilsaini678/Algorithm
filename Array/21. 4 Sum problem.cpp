/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findElements(vector<int> &arr,int key){
	int n = arr.size();
	vector<vector<int>> ans;
	for(int i=0;i<arr.size();i++){
		for(int j=i+1;j<arr.size()-1;j++){
			int left = arr[j+1];
			int right = arr[n-1];
			int sum = arr[i]+arr[j];
			vector<int> tmp(4,-1);
			while(left<right){
				if(sum+arr[left]+arr[right]==key){
					tmp = {i,j,left,right};
					ans.push_back(tmp);
					left++;
				}
				else if(sum+arr[left]+arr[right]<key){
					left++;
				}
				else {
					right--;
				}
			}
		}
	}
	return ans;
}


void solve()
{
	int n,key;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>key;
	
	/* Approach 1: Brute Force
		Run 4 nested loop and search for the possibilities.
		TC: O(N^4) SC: O(1)

	   Approach 2: Binary Search
	    Run 3 nested loop, and then search for the element using binary search. 
	    TC: O(N^3 logN) SC: O(1)
		
	   Approach 3: Hashing
	    Run 2 nested loop, and then search for the element using hash or sorting.
	    TC: O(N^3) SC: O(N)

	   Approach 4: Two Pointer
		Run 2 nested loop, and then search for the element using sorting.
		TC: O(N^3) SC: O(1)
	*/

	sort(arr.begin(),arr.end());
	vector<vector<int>> ans = findElements(arr,key);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
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
4
2 7 9 11
9


Output:
0 1

*/