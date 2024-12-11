/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findMajorityElement(vector<int> &arr){
	int major1 = 0, major2 = 0;
	int count1 = 0, count2 =0;
	int size = arr.size();
	for(int i=0;i<size;i++){
		if(count1==0 && arr[i]!=major2){
			major1 = arr[i];
			count1 = 1;
		}
		else if(count2==0 && arr[i]!=major1){
			major2 = arr[i];
			count2 = 1;
		}
		else if(arr[i]==major1){
			count1++;
		}
		else if(arr[i]==major2){
			count2++;
		}
		else {
			count1--;
			count2--;
		}
	}
	vector<int> ans(2,-1);
	count1=0;
	count2=0;
	for(int i=0;i<size;i++){
		if(arr[i]==major1){
			count1++;
		}
	}
	if(count1>size/3) ans[0]=major1;
	for(int i=0;i<size;i++){
		if(arr[i]==major2){
			count2++;
		}
	}
	if(count2>size/3) ans[1]=major2;
	return ans;
}


void solve()
{
	int n,x,y;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	
	/* Approach 1:
		Check for each element, if it occurs more than n/3 times, by iterating the entire array.
		TC: O(N*N) SC: O(1)

	   Approach 2:
	 	Use hashmap to store the frequency and then which element is occuring more than n/3 times.
	 	TC: O(N) SC: O(N)

	   Approach 3:
	   	Take two count variable, count1 and count2 and two major elment variable major1 and major2, for each index check:
	   	If count1 == 0, then element1 = arr[index]
	   	else if count2 == 0, then element2 = arr[index]
	   	else if element1 = arr[index] count1++
	   	else if element2 = arr[index] count2++
	   	else count1-- and count2--
	   	The logic is if at least 1 major element exist, then to cancel it n/3*2+2 element will be required to cancel it, which isn't possible.
	   	Since every 2 unmatch will cancel 1 frequency of the major element.
	   	If 2 majority element exists, then that is itself, N/3+1, N/3+1 i.e 2N/3+2 the elements which are left are N/3-2, which can't decrease 
	   	the count of both, we will always left with some element left for both majority element.
	    TC: O(N) SC: O(1) 	
	*/


	vector<int> ans = findMajorityElement(nums);
	for(auto it: ans){
		cout<<it<<" ";
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
5
1 2 2 3 3


Output:
3 2

*/