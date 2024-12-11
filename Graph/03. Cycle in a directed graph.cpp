/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

bool isCycleBfs(vector<int> graph[], int start, int n, vector<int> &indegree){
	queue<int> q;
	int count = 0;
	for(int i=1;i<indegree.size();i++){
		if(indegree[i]==0){
			q.push(i);
			count++;
		}
	}

	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(auto v: graph[u]){
			indegree[v]--;
			if(indegree[v]==0){
				q.push(v);
				count++;
			}
		}
	}
	return (count!=n);
}

bool isCycleDfs(vector<int> graph[], int start,vector<bool> &visited, vector<bool> &localvisited){
	visited[start] = true;
	localvisited[start] = true;
	for(auto v: graph[start]){
		if(visited[v]==false){
			if(isCycleDfs(graph,v,visited,localvisited)) return true;
		} else if(localvisited[v]==true){
			return true;
		}
	}
	localvisited[start] = false;
	return false;
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> graph[n+1];
	vector<int> indegree(n+1,0);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	
	// BFS
	for(int i=1;i<=n;i++){
		for(int j=0;j<graph[i].size();j++){
			indegree[graph[i][j]]++;
		}
	}
	(isCycleBfs(graph,1,n,indegree))?cout<<"Cycle is found"<<endl: cout<<"No cycle is found"<<endl;

	// DFS
	vector<bool> visited(n+1,false);
	vector<bool> localvisited(n+1,false);
	(isCycleDfs(graph,1,visited,localvisited))?cout<<"Cycle is found"<<endl: cout<<"No cycle is found"<<endl;
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
Cycle is found
Cycle is found

*/