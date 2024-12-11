/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

bool isBipartiteBfs(vector<int> graph[], int start, int n){
	queue<pair<int,int>> q;
	vector<int> color(n,-1);
	q.push({start,0});
	color[start] = 0;
	while(!q.empty()){
		auto [u, pcolor] = q.front();
		q.pop();
		for(auto v: graph[u]){
			if(color[v]==-1){
				color[v] = 1 - pcolor;
				q.push({v,color[v]});
			} else if(color[v]==pcolor){
				return false;
			}
		}
	}
	return true;
}

bool isBipartiteDfs(vector<int> graph[], int start,int pcolor,vector<int> &color){
	color[start] = 1 - pcolor;
	for(auto v: graph[start]){
		if(color[v]!=-1){
			if(!isBipartiteDfs(graph,v,color[start],color)) return false;
		} else if(color[v]==color[start]){
			return false;
		}
	}
	return true;
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
	vector<int> color(n+1, -1);
	(isBipartiteBfs(graph,1,n))?cout<<"Graph is bipartite"<<endl: cout<<"Graph isn't bipartite"<<endl;
	(isBipartiteDfs(graph,1,0,color))?cout<<"Graph is bipartite"<<endl: cout<<"Graph isn't bipartite"<<endl;
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
Graph is bipartite
Graph is bipartite


*/