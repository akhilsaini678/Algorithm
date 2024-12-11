/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

// Moore Voting Algorithm
int findMajorityElement(vector<int> &arr){
	int major = arr[0];
	int count = 1;
	int size = arr.size();
	for(int i=1;i<size;i++){
		if(count==0){
			major = arr[i];
			count=1;
		} else if(major == arr[i]){
			count++;
		}
		else {
			count--;
		}
	}
	return major;
}


void solve()
{
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	
	/* Approach 1:
		Check for each element, if it occurs more than n/2 times, by iterating the entire array.
		TC: O(N*N) SC: O(1)

	   Approach 2:
	 	Use hashmap to store the frequency and then which element is occuring more than n/2 times.
	 	TC: O(N) SC: O(N)

	   Approach 3:
	   	Take two variable, count and element, for each index check:
	   	If count == 0, then element = arr[index]
	   	else if element = arr[index] count++
	   	else count--
	   	The logic is that the frequency of element will be more than rest of the element.
	   	So even if all the other elements will be unique then also at the end, we will be left with only one element i.e more than n/2 times.
	*/


	int element = findMajorityElement(nums);
	cout<<element<<endl;
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
7
2 2 1 1 1 2 2


Output:
2

*/