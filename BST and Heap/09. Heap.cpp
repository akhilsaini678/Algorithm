/*
 Akhil Saini
*/
#include <bits/stdc++.h>
using namespace std;

class Heap {
public: 
	int capacity;
	int size;
	int* arr;
	Heap(int c){
		this->size = 0;
		this->capacity = c;
		this->arr = new int[c];
	}

	int parent(){
		return (i-1)/2;
	}

	int left(){
		return (2*i+1);
	}

	int right(){
		return (2*i+2);
	}

	void insert(int val){
		if(size==capacity) return;
		size++;
		arr[size-1] = val;
		for(int i=size-1;i!=0&&arr[parent(i)]>arr[i];){
			swap(arr[parent(i)],arr[i]);
			i = parent(i);
		}
	}

	void heapify(int index){
		int left = left(index);
		int right = right(index);
		int smallest = index;
		if(left<size&&arr[smallest]>arr[left]) smallest=left;
		if(right<size&&arr[smallest]>arr[right]) smallest=right;
		if(smallest==index) return;
		swap(arr[smallest],arr[index]);
		heapify(smallest);


	}
};

void solve()
{

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