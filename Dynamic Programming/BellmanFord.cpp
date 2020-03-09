#include <iostream>

#define INF 999
#define V 7

using namespace std;

void printSolution(int dist[V])
{
    cout << "Distance form source vertex:" << endl;
    cout << "Vertex       Distance from source" << endl;
    for(int i=0; i<V; i++)
        cout << i << "     " << dist[i] << endl;

}

void BellmanFord(int graph[V][V], int src)
{
    int dist[V];
    for(int k=0; k<V; k++)
        dist[k]= INF;
    dist[src] = 0;

    for(int rlx = 0; rlx<V-1; rlx++) // Relaxation performing V-1 times
     for(int u=0; u<V; u++)
    {
        for(int v=0; v<V; v++)
            if(graph[u][v]+dist[u]<dist[v] && graph[u][v]!= INF && dist[u] != INF)
                dist[v] = graph[u][v]+dist[u];
    }

    // check for negative weighted cycle
    // if we get smaller path again then there will be negative weighted cycle
   for(int rlx = 0; rlx<V-1; rlx++) // Relaxation performing V-1 times
     for(int u=0; u<V; u++)
    {
        for(int v=0; v<V; v++)
            if(graph[u][v]+dist[u]<dist[v] && graph[u][v]!= INF && dist[u] != INF)
               { cout << "Negative weighted cycle found!!";
                return; }
    }

    printSolution(dist);
}



int main()
{
    int graph[V][V] = { { 0,6,5,5,INF,INF,INF},
            { INF,0,INF,INF,-1,INF,INF },
            { INF,-2,0,INF,1,INF,INF},
            { INF,INF,-2,0,INF,-1,INF},
            { INF,INF,INF,INF,0,INF,3},
            {INF,INF,INF,INF,INF,0,3},
            {INF,INF,INF,INF,INF,INF,0} };

       BellmanFord(graph,0);

      return 0;

}
