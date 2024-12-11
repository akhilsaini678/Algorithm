/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getPascalTriangle(int n){
	vector<vector<int>> pascalTri;
	pascalTri.push_back({1});
	for(int i=1;i<n;i++){
		vector<int> row(i+1);
		row[0] = row[i] = 1;
		for(int j=1;j<i;j++){
			row[j] = pascalTri[i-1][j-1] + pascalTri[i-1][j]; 
		}
		pascalTri.push_back(row);
	}
	return pascalTri;
}

vector<int> getPascalTriangleRow(int n){
	int ans = 1;
	int deno = 1;
	vector<int> row;
	row.push_back(1);
	for(int i=0;i<n;i++){
		ans*= (n-i);
		ans/=(i+1);
		row.push_back(ans);
	}
	return row;
}

int getPascalTriangleElement(int n,int m){
	int ans = 1;
	int deno = 1;
	for(int i=0;i<m;i++){
		ans*= (n-i);
		ans/= (i+1);
	}
	return ans;
}


void solve()
{
	int n,m;
	cin>>n>>m;
	// T.C: O(N*N) and S.C: O(N)
	vector<vector<int>> pascalTriangle = getPascalTriangle(n);
	
	// T.C: O(N) and S.C: O(1)
	vector<int> pascalTriangleRow = getPascalTriangleRow(n);
	
	// T.C: O(M) and S.C: O(1)
	int pascalTriangleEleemnt = getPascalTriangleElement(n,m);
	

	// Printing the results
	for(auto row:pascalTriangle){
		for(auto ele: row){
			cout<<ele<<" ";
		}
		cout<<endl;
	}

	for(auto it: pascalTriangleRow){
		cout<<it<<" ";
	}
	cout<<endl;

	cout<<pascalTriangleEleemnt<<endl;
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
6 2

Output:
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
15

*/