/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void MST(vector<pair<int,int>> graph[], int start, int n){
	vector<bool> visited(n+1,false);
	priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
	vector<vector<int>> mst;
	int mstSum = 0;
	pq.push({0,{1,-1}});
	while(!pq.empty()){
		auto [wt, edge] = pq.top();
		auto [u, parent] = edge;
		pq.pop();
		if(visited[u]==false){
			mstSum += wt;
			visited[edge.first] = true;
		}
		for(auto [v, wt]: graph[u]){
			if(visited[v]==false){
				pq.push({wt,{v,u}});
			}
		}
	}
	cout<<mstSum<<endl;
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
	MST(graph,1,n);
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
15

*/