/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string &str){
	int ans = 0, left = 0;
	unordered_map<char,int> maps;
	for(int i=0;i<str.size();i++){
		if(maps.find(str[i])==maps.end()){
			maps[str[i]]=1;
			ans = max(ans,i-left+1);
		} else {
			while(maps.find(str[i])!=maps.end()){
				maps.erase(str[left]);
				left++;
			}
			maps[str[i]]=1;
		}
	}
	return ans;
}


void solve()
{
	string str;
	cin>>str;
	
	/* Approach 1: Brute Force
		Get all the substrings and find out the maximum length from that, which is unique.
		TC: O(N^2) SC: O(1)

	   Approach 2: Two pointer approach
	    Keep a left pointer in the start, and iterate the string, while iterating put all
	    the traversed element into the hashmap. Once we had, the duplicate element move the 
	    left pointer unless it is not duplicate. And at each index take the maximum of index-left.
	    TC: O(N) SC: O(N)
		
	*/

	cout<<longestSubstring(str)<<endl;

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
abcabcbb


Output:
3

*/