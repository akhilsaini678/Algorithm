/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
	int leftSize = mid+1-low;
	int rightSize = high - mid;
	int k = low;
	vector<int> left(leftSize),right(rightSize);
	for(int i=0;i<leftSize;i++) left[i] = arr[k++];
	for(int i=0;i<rightSize;i++) right[i] = arr[k++];
	int i = 0, j = 0;
	k = low;
	while(i<leftSize&&j<rightSize){
		arr[k++] = (left[i]<right[j])?left[i++]:right[j++];
	}
	while(i<leftSize){
		arr[k++] = left[i++];
	}
	while(j<rightSize){
		arr[k++] = right[j++];
	}
}


int countPairs(vector<int> &arr, int low, int mid, int high){
	int right = mid+1;
	int ans = 0;
	for(int i=low;i<=mid;i++){
		while(right<=high && arr[i]>(2*arr[right])) right++;
		ans = ans + (right - (mid + 1));
	}
	return ans;
}

int countReversePair(vector<int> &arr, int low, int high){
	int count = 0;
	if(low<high){
		int mid = low + (high - low)/2;
		count +=countReversePair(arr,low,mid);
		count +=countReversePair(arr,mid+1,high);
		count += countPairs(arr,low,mid,high);
		merge(arr,low,mid,high);
	}
	return count;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	
	/* Approach 1:
		Traverse the array from 0 to n-1, and for each i, run a nested loop to check:
		If arr[i]>2*arr[j].
		TC: O(N*N) SC: O(1)

	   Approach 2:
	   Use merge sort, before merging both the array:
	   Compare left and right array, from index i = low, j = mid+1
	   If arr[i]> 2*arr[j] j++;
	   else break and add j-mid-1 to the answer.

	   Key Point: While traversing second array, we will not reset the index j
	   Reason being, if a value has already satisfied the condition for some number
	   Then it will satisfy the condition for bigger number too.
	   That is if 3 already add 1 to the answer.
	   Then 4 will also add at least 1 or more.
	   TC: O(2*NLogN) SC: O(N)
	*/

	int ans = countReversePair(arr,0,n-1);
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
1 3 2 3 1


Output:
2

*/