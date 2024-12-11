/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroes1(vector<vector<int>> &mat){
	int n = mat.size(),  m = mat[0].size();
	// Unordered_map, doesn't take pair as key
	map<pair<int,int>,int> maps;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]==0){
				for(int k=0;k<n;k++){ maps[{k,j}] = 1; }
				for(int l=0;l<m;l++){ maps[{i,l}] = 1; }
			}
		}
	}
	for(auto it:maps){
		mat[it.first.first][it.first.second] = 0;
	}
}

void setMatrixZeroes2(vector<vector<int>> &mat){
	int n = mat.size(),  m = mat[0].size();
	vector<int> row(n), col(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j]==0){
				row[i] = col[j] = 1;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(row[i]==1){
			for(int j=0;j<m;j++) mat[i][j] = 0;
		}
	}
	for(int j=0;j<m;j++){
		if(col[j]==1){
			for(int i=0;i<n;i++) mat[i][j] = 0;
		}
	}
}

void setMatrixZeroes3(vector<vector<int>> &mat){
	int n = mat.size(),  m = mat[0].size();
	bool rowFirst = false, colFirst = false;
	for(int i=0;i<n;i++){ if(mat[i][0] == 0) { colFirst = true; break; } }
	for(int i=0;i<m;i++){ if(mat[0][i] == 0) { rowFirst = true; break; } }
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(mat[i][j]==0){
				mat[i][0] = mat[0][j] = 0;
			}
		}
	}

	for(int i=1;i<n;i++){
		if(mat[i][0]==0){
			for(int j=1;j<m;j++) mat[i][j] = 0;
		}
	}
	for(int j=1;j<m;j++){
		if(mat[0][j]==0){
			for(int i=1;i<n;i++) mat[i][j] = 0;
		}
	}

	if(rowFirst){
		for(int i=0;i<m;i++){ mat[0][i] = 0; }
	}
	if(colFirst){
		for(int i=0;i<n;i++){ mat[i][0] = 0; }
	}
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> mat(n,vector<int> m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	setMatrixZeroes1(mat); // T.C: O(N*M*(N+M)) and S.C: O(N*M)
	setMatrixZeroes2(mat); // T.C: O(N*M) and S.C: O(N+M)
	setMatrixZeroes3(mat); // T.C: O(N*M) and S.C: O(1)
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