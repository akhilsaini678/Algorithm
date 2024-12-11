/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int start,vector<bool> &visited, stack<int> &st, int flag){
	visited[start] = true;
	for(auto v: graph[start]){
		if(visited[v]==false){
			dfs(graph,v,visited,st,flag);
		}
	}
	if(flag) st.push(start);
}

void reverse(vector<int> graph[], vector<int> rev[],int n){
	for(int i=1;i<=n;i++){
		for(int j=0;j<graph[i].size();j++){
			rev[graph[i][j]].push_back(i);
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
	}

	vector<bool> visited(n+1,false);
	stack<int> st;
	int cntComponent = 0;
	vector<int> rev[n+1];

	// Step 1: Sort the nodes, according to their finishing time.
	dfs(graph,1,visited,st,1);

	// Step 2: Reversing the edges.
	reverse(graph,rev,n);
	visited.assign(n+1,false);
	
	// Step 3: Traversing the components using DFS
	while(!st.empty()){
		int start = st.top();
		st.pop();
		if(visited[start]==false){
			cntComponent++;
			dfs(rev,start,visited,st,0);
		}
	}
	cout<<cntComponent<<endl;
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
8 7
1 2
2 5
2 6
3 4
4 8
7 3
8 7



Output:
2
2

*/