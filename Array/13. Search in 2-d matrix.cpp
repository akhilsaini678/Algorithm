/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;


bool search(vector<vector<int>> &mat, int key){
	int n = mat.size(), m = mat[0].size();
	int low = 0, high = n*m-1;
	while(low<=high){
		int mid = low + (high-low)/2;
		int row = mid/m;
		int col = mid%m;
		if(mat[row][col]==key) return true;
		else if(mat[row][col]<key) low = mid+1;
		else high = mid-1;
	}
	return false;
}

void solve()
{
	int n,m,key;
	cin>>n>>m;
	vector<vector<int>> mat(n,vector<int> (m,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mat[i][j];
	cin>>key;
	
	/* Approach 1:
		Do a linear search in the matrix.
		TC: O(N*M) S.C: O(1)

	   Approach 2:
		Do a binary search in each row.
		TC: O(N*Log(M)) S.C: O(1)

	   Approach 3:
	   	Treat this 2-d array indexes as a single range of bianry search.
	   	To get the row: mid/row
	   	To get the col: mid%row
	   	TC: O(Log(N*M)) S.C: O(1)
	*/
	cout<< search(mat,key) <<endl;			
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
3 4
1 2 3 4
5 6 7 8 
9 10 11 12
9

Output:
1

*/