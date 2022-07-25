/*
    Watch this for understanding - https://www.youtube.com/watch?v=FtN3BYH2Zes
    Single source shortest path
    Detecting Negative weight cycle 
    Approach - DP (Try All possible ways) Time Complexity:- O(V * E)
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
{   
    //assuming there is no -ve weight cycle all edes shuld be relaxed in V-1 iterations
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    int E = adj.size();

    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : adj)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            //relaxation
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> adj = {{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
    int S = 2;
    int V = 3;
    vector<int> dist = bellman_ford(V, adj, S);

    for(int n: dist){
        cout<<n<<" ";
    }
    cout<<endl;

    return 0;
}