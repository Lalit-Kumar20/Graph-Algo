#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define V 9
int minKey(int dist[V],bool sptSet[V])
{
	int mi = INT_MAX,index ;
	for(int i =0 ;i<V;i++)
	{
		if(sptSet[i]==0 && dist[i]<=mi)
		{
			mi = dist[i];
			index = i;
		}
	}
	return index ;
}
void print(int dist[V])
{   cout<<"distance from\nsource to node\n";
	for(int i = 0;i<V;i++)
	{
		cout<<i<<"\t"<<dist[i]<<endl;
	}
}
void dijkstra(int graph[V][V],int src)
{
	int dist[V];
	bool sptSet[V];
	for(int i = 0;i<V;i++)
	{
		sptSet[i] = 0;
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	for(int i = 0;i<V-1;i++)
	{
		int u = minKey(dist,sptSet);
		sptSet[u] = 1;
		for(int j = 0;j<V;j++)
		{
			if(sptSet[j]==0 && graph[u][j] && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j])
			{
				dist[j]= dist[u]+graph[u][j];
			}
		}
	}
	print(dist);
	
}
int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph,0); 
}
