/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

// Recursive
int pow1(int x,int n){
	if(n==0) return 1;
	if(n%2) return x*pow(x,n-1);
	return pow(x*x,n/2);
}

// Iterative
int pow2(int x,int n){
	int ans = 1; 
	while(n!=0){
		if(n%2){
			ans = ans*x;
			n = n-1;

		} else {
			x = x*x;
			n = n/2;
		}
	}
	return ans;
}

void solve()
{
	int n,x;
	cin>>x>>n;
	
	
	/* Brute force:
		Multiply x, n times by iterating n from 1 to n
		TC: O(N) SC: O(1)

	   Optimal Solution:
	 	If x is power of 2, then I can square the number and decrease the power by dividing it 2.
	 	TC: O(NlogN) SC: O(N)
	*/


	int ans = pow2(x,n);
	cout<<ans<<endl;
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
12


Output:
4096

*/