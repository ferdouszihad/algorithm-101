#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(100005);
bool visited[100005];
int parent[100005];
void bfs(int src)
{

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int node : adj[f])
        {

            if (!visited[node])
            {
                q.push(node);
                visited[node] = true;
                parent[node] = f;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    int m = n, u = 1;

    while (e--)
    {
        int n1, n2;
        cin >> n1 >> n2;

        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    bfs(u);

    vector<int> finalPath;

    while (m != -1)
    {
        finalPath.push_back(m);
        m = parent[m];
    }
    if (finalPath.size() <= 1)
    {

        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << finalPath.size() << endl;

    reverse(finalPath.begin(), finalPath.end());

    for (int node : finalPath)
    {

        cout << node << " ";
    }

    return 0;
}