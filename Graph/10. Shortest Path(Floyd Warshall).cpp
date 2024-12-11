/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void shortestPath(vector<vector<int>> &matrix, int start, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==-1) matrix[i][j]=1e9+7;
			if(i==j) matrix[i][j] = 0;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
			}
		}
	}

	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> matrix(n,vector<int> (n,-1));
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		matrix[u-1][v-1] = wt;
		matrix[v-1][u-1] = wt;
	}
	shortestPath(matrix,1,n);
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
8 8
1 2 2
1 3 1
2 5 3
2 6 3
3 4 6
4 8 1
3 7 2 
7 8 3


Output:
0 2 1 7 5 5 3 6 
2 0 3 9 3 3 5 8 
1 3 0 6 6 6 2 5 
7 9 6 0 12 12 4 1 
5 3 6 12 0 6 8 11 
5 3 6 12 6 0 8 11 
3 5 2 4 8 8 0 3 
6 8 5 1 11 11 3 0 

*/