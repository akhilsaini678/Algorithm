/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

pair<int,int> findElements(vector<int> &arr,int key){
	int left = 0, right = arr.size()-1;
	pair<int,int> ans = {-1,-1};
	while(left<right){
		if(arr[left]+arr[right]==key) {
			ans = {left,right};
			return ans;
		}
		if(arr[left]+arr[right]<key) left++;
		else if(arr[left]+arr[right]>key) right--;
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
		Traverse the array from 0 to n-1 and for each i, run a nested loop, and check for the element, key - arr[i]
		TC: O(N*N) SC: O(1)

	   Approach 2: Hashing
	   Use hashing, start iterating from 0 to n-1:
	   For each index, checks if maps contains key-arr[i], if so then we have an answer.
	   After this check, insert the array element into the matrix.
	   TC: O(N) SC: O(N)

		Approach 3: Two Pointer
		Sort the array and set two pointers left and right on first and last index respectively.
		If the key = arr[left]+arr[right], then left and right is the answer.
	*/

	sort(arr.begin(),arr.end());
	pair<int,int> ans = findElements(arr,key);
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
4
2 7 9 11
9


Output:
0 1

*/