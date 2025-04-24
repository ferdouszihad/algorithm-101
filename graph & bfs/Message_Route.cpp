#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
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

        for (int n : adj_list[f])
        {
            if (!visited[n])
            {
                q.push(n);
                visited[n] = true;
                parent[n] = f;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    bfs(1);
    if (!visited[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> path;
    int node = n;
    int c = 0;

    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
        c++;
    }

    reverse(path.begin(), path.end());
    cout << c << endl;
    for (int n : path)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}