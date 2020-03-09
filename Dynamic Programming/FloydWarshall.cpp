#include <iostream>

#define INF 999
#define V 4

using namespace std;

void floydWarshall(int graph[V][V])
{
    int tempGraph[V][V];
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            tempGraph[i][j] = graph[i][j];

    for(int k=0; k<V; k++)   // Going through vertex
    {
        for(int i=0; i<V; i++)  // i and j only for matrix
        {
            for(int j=0; j<V; j++)
            {
                tempGraph[i][j] = min(tempGraph[i][j],tempGraph[i][k]+tempGraph[k][j]);

            }
        }

    }

        // Printing solution
        for(int y=0; y<V; y++,cout << endl)
            for(int z=0; z<V; z++)
               cout << tempGraph[y][z] << " ";

}

int main()
{
    int graph[V][V] = {
    { 0,3,INF,7},
    {8,0,2,INF },
    { 5 , INF, 0,1 },
    { 2,INF,INF,0}};

   floydWarshall(graph);

}
