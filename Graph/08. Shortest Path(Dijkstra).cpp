/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void shortestPath(vector<pair<int,int>> graph[], int start, int n){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<int> dist(n+1,1e9+7);
	pq.push({0,start});
	dist[start] = 0;
	while(!pq.empty()){
		auto [d, curr] = pq.top();
		pq.pop();
		for(auto [v,wt]: graph[curr]){
			if(dist[curr]+wt<dist[v]){
				dist[v]=dist[curr]+wt;
				pq.push({dist[v],v});
			}
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
	vector<pair<int,int>> graph[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		graph[u].push_back({v,wt});
		graph[v].push_back({u,wt});
	}
	shortestPath(graph,1,n);
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