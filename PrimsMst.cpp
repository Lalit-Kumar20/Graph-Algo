#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define V 5
int minKey(int key[V],bool mstSet[V])
{
	int mi = INT_MAX,index;
	for(int i = 0;i<V;i++)
	{
		if(key[i]<mi && mstSet[i]==0)
		{
			index = i;
			mi = key[i];
		}
	}
	return index;
}
void print(int parent[V],int graph[V][V])
{
	for(int i = 1;i<V;i++)
	{
		cout<<parent[i]<<'-'<<i<<" "<<graph[i][parent[i]]<<endl;
	}
}
void primMST(int graph[V][V])
{
	int key[V];
	bool mstSet[V];
	int parent[V];
	for(int i = 0;i<V;i++)
	{
		key[V]=INT_MAX;
		mstSet[V]=0;
	}
	key[0]=0;
	parent[0]=-1;
	for(int i = 0;i<V-1;i++)
	{
		int u = minKey(key,mstSet);
		mstSet[u]=1;
		for(int j = 0;j<V;j++)
		{
			if(graph[u][j] && mstSet[j]==0 && graph[u][j]<key[j])
			{
				parent[j]=u;
				key[j]=graph[u][j];
			}
		}
	}
	print(parent,graph);
	
}
int main()
{
	 int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
    primMST(graph); 
 
}
