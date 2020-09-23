#include<bits/stdc++.h>
using namespace std;
#define V 4
const int INF = 9999999;
void print(int dist[V][V])
{
	for(int i = 0;i<V;i++)
	{
		for(int j = 0;j<V;j++)
		{
			if(dist[i][j]==INF)
			{
				cout<<"INF"<<' ';
			}
			else {
				cout<<dist[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

void warshall(int graph[V][V])
{  //initialize every dist same as graph
	int dist[V][V];
	for(int i = 0;i<V;i++)
	{
		for(int j = 0;j<V;j++)
		{
			dist[i][j]=graph[i][j];
		}
	}
	//check for vertice to be included
	for(int k = 0;k<V;k++)
	{
		//source
		for(int i = 0;i<V;i++)
		{ 
		   //destination
			for(int j = 0;j<V;j++)
			{  
			
			   //if including the vertex make path smalleer
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	print(dist);
}
int main()  
{   int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
  warshall(graph);  
    return 0;  
}  
