/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSortBFS(vector<int> graph[], int start, int n, vector<int> &indegree){
	queue<int> q;
	vector<int> topoSort;
	for(int i=1;i<indegree.size();i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	while(!q.empty()){
		auto u = q.front();
		q.pop();
		topoSort.push_back(u);
		for(auto v: graph[u]){
			indegree[v]--;
			if(indegree[v]==0){
				q.push(v);
			}
		}
	}
	return topoSort;
}

void topologicalSortDfs(vector<int> graph[], int start, vector<bool> &visited, stack<int> &topoSort){
	visited[start] = true;
	for(auto v: graph[start]){
		if(visited[v]==false){
			topologicalSortDfs(graph,v,visited,topoSort);
		}
	}
	topoSort.push(start);
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
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<graph[i].size();j++){
			indegree[graph[i][j]]++;
		}
	}
	vector<int> topoSort = topologicalSortBFS(graph,1,n,indegree);
	for(auto node: topoSort) cout<<node<<" ";
	cout<<endl;

	vector<bool> visited(n+1,false);
	vector<int> topoSort1;
	stack<int> st;
	topologicalSortDfs(graph, 1, visited, st);
	while(!st.empty()){
		topoSort1.push_back(st.top());
		st.pop();
	}
	for(auto node: topoSort1) cout<<node<<" ";
	cout<<endl;

	// (isCycleDfs(graph,1,visited,localvisited))?cout<<"Cycle is found"<<endl: cout<<"No cycle is found"<<endl;
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
3 7
8 7


Output:
1 2 3 5 6 4 8 7 
1 3 4 8 7 2 6 5 

*/