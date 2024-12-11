/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &mat){
	int n = mat.size(), m = mat[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			swap(mat[i][j],mat[j][i]);
		}
	}
}

void rev(vector<vector<int>> &mat){
	int n = mat.size(), m = mat[0].size();
	for(int i=0;i<n;i++){
		reverse(mat[i].begin(),mat[i].end());
	}
}

void rotate(vector<vector<int>> &mat){
	transpose(mat);
	rev(mat);
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> mat(n,vector<int> (m,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mat[i][j];
	
	/* One approach is:
		Take another matrix and copy last column as 1st row, second last as 2nd row, and so on.
		TC: O(N*M) S.C: O(N*M)
	*/

	/* Second approach is:
		Take the transpose of the matrix and reverse the rows
		TC: O(2*N*M) S.C: O(1)
	*/
	rotate(mat);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
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
3 3
1 2 3
4 5 6
7 8 9

Output:
7 4 1 
8 5 2 
9 6 3 
*/