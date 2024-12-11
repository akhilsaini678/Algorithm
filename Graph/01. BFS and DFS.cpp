/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> graph[], int start, int n){
	queue<int> q;
	vector<bool> visited(n,false);
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		cout<<u<<" ";
		for(auto v: graph[u]){
			if(visited[v]==false){
				q.push(v);
				visited[v]=true;
			}
		}
	}
}

void dfs(vector<int> graph[], int start,vector<bool> &visited){
	visited[start] = true;
	cout<<start<<" ";
	for(auto v: graph[start]){
		if(visited[v]==false){
			dfs(graph,v,visited);
		}
	}
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
	bfs(graph,1,n);
	cout<<endl;
	dfs(graph,1,visited);
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
1 2
1 3
2 5
2 6
3 4
4 8
7 3
8 7


Output:
1 2 3 5 6 4 7 8 
1 2 5 6 3 4 8 7 

*/