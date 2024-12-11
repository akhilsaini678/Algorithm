/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> ranked;

struct node {
	int u;
	int v;
	int wt;
	node(int u, int v, int wt){
		this->u = u;
		this->v = v;
		this->wt = wt;
	}
};

bool cmp(node a, node b){
	return a.wt<b.wt;
}


int find_parent(int u){
	if(parent[u]==u)
		return u;
	return parent[u] = find_parent(parent[u]);
}

void union_(int u,int v){
	
	int x = find_parent(u);
	int y = find_parent(v);

	if(ranked[x]>ranked[y]){
		parent[y] = x;
	} else if(ranked[x]<ranked[y]){
		parent[x] = y;
	} else {
		parent[x] = y;
		ranked[x]++;
	}
}



void shortestPath(vector<node> &edges, int start, int n){
	sort(edges.begin(),edges.end(),cmp);
	int mstSum = 0;
	for(int i=0;i<edges.size();i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int wt = edges[i].wt;
		if(find_parent(u)!=find_parent(v)){
			union_(u,v);
			mstSum+=wt;
		}
	}
	cout<<mstSum<<endl;
}


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<node> edges;
	for(int i=0;i<m;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.push_back({u-1,v-1,wt});
	}
	parent.resize(n);
	ranked.resize(n);
	for(int i=0;i<n;i++){
		parent[i] = i;
		ranked[i] = 0;
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
15

*/