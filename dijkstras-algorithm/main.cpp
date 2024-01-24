#include <bits/stdc++.h>
#include <vector>
#include <climits>

using namespace std;

ifstream in("dijkstra.in");
ofstream out("dijkstra.out");
#define cin in
#define cout out

void printSolution(int dist[], int vCount);
void dijkstra(vector<vector<int>> graph, int vCount, int src);
int minDistance(int dist[], bool sptSet[], int vCount);

int main()
{
    // use sample adjacency matrix graph
    int vCount, n, m, tmp;
    vector<vector<int>> graph;

    cin >> vCount;

    for (n = 0; n < vCount; n++)
    {
        vector<int> temp;
        for (m = 0; m < vCount; m++)
        {
            cin >> tmp;
            temp.push_back(tmp);
        }
        graph.push_back(temp);
    }


    

    dijkstra(graph, vCount, 0);

    return 0;
}

void printSolution(int dist[], int vCount)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < vCount; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(vector<vector<int>> graph, int vCount, int src)
{
    // minimum distance found to node from source node
    int dist[vCount];
    // true if fully processed
    bool sptSet[vCount];

    // initialize dist and sptSet
    for ( int n = 0; n < vCount; n++)
    {
        dist[n] = INT_MAX;
        sptSet[n] = false;
    }

    // mark src as starting point
    dist[src] = 0;

    for ( int n = 0; n < vCount - 1; n++ )
    {
        int cur = minDistance(dist, sptSet, vCount);

        sptSet[cur] = true;

        for ( int next = 0; next < vCount; next++ )
        {
            // update dist[cur] only if
            // it is next is not processed
            // there is an edge between cur and next
            // if cur is reachable from source
            // if distance from current to next is less than dist[next]
            if (!sptSet[next]
                && graph[cur][next] 
                && dist[cur] != INT_MAX
                && (dist[cur] + graph[cur][next]) < dist[next])
            {
                dist[next] = dist[cur] + graph[cur][next];
            }
        }
    }

    printSolution(dist, vCount);
}

int minDistance(int dist[], bool sptSet[], int vCount)
{
    int min = INT_MAX, minIndex;

    for ( int v = 0; v < vCount; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            minIndex = v;
            min = dist[v];
        }
    }

    return minIndex;
}