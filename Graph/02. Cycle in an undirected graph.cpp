/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

bool isCycleBfs(vector<int> graph[], int start, int n){
	queue<pair<int,int>> q;
	vector<bool> visited(n,false);
	q.push({start,-1});
	visited[start] = true;
	while(!q.empty()){
		auto [u, parent] = q.front();
		q.pop();
		for(auto v: graph[u]){
			if(visited[v]==false){
				q.push({v,u});
				visited[v]=true;
			} else if(v!=parent){
				return true;
			}
		}
	}
	return false;
}

bool isCycleDfs(vector<int> graph[], int start,int parent,vector<bool> &visited){
	visited[start] = true;
	for(auto v: graph[start]){
		if(visited[v]==false){
			if(isCycleDfs(graph,v,start,visited)) return true;
		} else if(v!=parent){
			return true;
		}
	}
	return false;
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> graph[n+1];
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<bool> visited(n+1);
	// BFS
	(isCycleBfs(graph,1,n))?cout<<"Cycle is found"<<endl: cout<<"No cycle is found"<<endl;
	// DFS
	(isCycleDfs(graph,1,-1,visited))?cout<<"Cycle is found"<<endl: cout<<"No cycle is found"<<endl;
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


Output:


*/