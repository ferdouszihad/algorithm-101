#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visited[1005];
void dfs(int src)
{
    visited[src] = true;

    for (int node : adj[src])
        if (!visited[node])
            dfs(node);
}

int main()
{

    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    int src;
    cin >> src;
    memset(visited, false, sizeof(visited));
    dfs(src);
    int count = 0;
    for (bool v : visited)
    {
        if (v)
            count++;
    }
    cout << count << endl;

    return 0;
}