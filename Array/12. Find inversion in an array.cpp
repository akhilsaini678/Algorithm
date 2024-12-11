/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums,int low,int mid,int high){
	int leftSize = mid+1-low;
	int rightSize = high - mid;
	int k = low, i = 0, j = 0, count = 0;
	vector<int> left(leftSize), right(rightSize);
	for(int i=0;i<leftSize;i++) left[i] = nums[k++];
	for(int i=0;i<rightSize;i++) right[i] = nums[k++];
	k = low, i = 0 , j = 0;
	while(i<leftSize&&j<rightSize){
		if(left[i]<right[j]){
			nums[k++] = left[i++];
		}
		else {
			count += (leftSize - i);
			nums[k++] = right[j++];
		}
	}
	while(i<leftSize){
		nums[k++] = left[i++];
	}
	while(j<rightSize){
		nums[k++] = right[j++];
	}
	return count;
}

int findInversion(vector<int> &nums,int low,int high){

	int inversionCount = 0;
	if(low<high){
		int mid = low+(high-low)/2;
		inversionCount+=findInversion(nums,low,mid);
		inversionCount+=findInversion(nums,mid+1,high);

		inversionCount+=merge(nums,low,mid,high);
	}
	return inversionCount;
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
		Iterate through the array, and calculate inversions for each index while traversing in a nested loop.
		TC: O(N*N) SC: O(1)

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
5
5 3 2 1 4


Output:
7

*/