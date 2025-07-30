#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visited[1005];
void dfs(int src)
{
    visited[src] = true;
    // cout << src << endl;
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

    memset(visited, false, sizeof(visited));

    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {
            count++;
            dfs(i);
        }
    }

    cout << count << endl;

    return 0;
}