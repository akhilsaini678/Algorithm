/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void shortestPath(vector<vector<int>> &edges, int start, int n){
	
	vector<int> dist(n+1,1e9+7);
	dist[1] = 0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<edges.size();j++){
			int u =edges[j][0];
			int v =edges[j][1];
			int wt =edges[j][2];
			if(dist[u]+wt<dist[v]){
				dist[v] = dist[u]+wt;
			}
		}
	}

	// Negative Cycle:
	for(int j=0;j<edges.size();j++){
		int u =edges[j][0];
		int v =edges[j][1];
		int wt =edges[j][2];
		if(dist[u]+wt<dist[v]){
			cout<<"Negative Cycle"<<endl;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edges;
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.push_back({u,v,wt});
	}
	shortestPath(edges,1,n);
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

*/