#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
bool visited[1005];
int c = 0;
void dfs(int src)
{
    visited[src] = true;
    c++;

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

    vector<int> gs;
    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {
            dfs(i);
            gs.push_back(c);
            c = 0;
        }
    }

    sort(gs.begin(), gs.end());

    for (int size : gs)
    {
        cout << size << " ";
    }

    return 0;
}