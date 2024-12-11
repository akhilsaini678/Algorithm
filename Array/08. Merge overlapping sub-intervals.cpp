/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> mergeRanges(vector<pair<int,int>> &intervals){
	int n = intervals.size();
	sort(intervals.begin(),intervals.end());
	pair<int,int> tmp = intervals[0];
	vector<pair<int,int>> ans;
	for(int i=1;i<n;i++){
		if(tmp.second<intervals[i].first){
			ans.push_back(tmp);
			tmp = intervals[i];
		} else {
			tmp.second = max(tmp.second,intervals[i].second);
		}
	}
	ans.push_back(tmp);
	return ans;
}

void solve()
{
	int n,x,y;
	cin>>n;
	vector<pair<int,int>> intervals(n);
	for(int i=0;i<n;i++){
		cin>>x>>y;
		intervals[i] = make_pair(x,y);
	}
	
	/* One approach is:
		Iterate the array from 0 to n-1, for each i, check the range and insert the 
		merged range into a set. Do it for each i.
		TC: O(N*N) S.C: O(1)
	*/

	/* Second approach is:
		1. Sort the array according to first element.
		2. Iterate the array and check if the current range can have the next eleemnt or not.
		3. If not insert that last range into the ans, and make the index i as current range.
		TC: O(2*N*M) S.C: O(1)
	*/

	vector<pair<int,int>> ans;
	ans = mergeRanges(intervals);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
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
2
4
1 3 
2 6
8 10
15 18
2
1 4
4 5


Output:
1 6
8 10
15 18
1 5

*/