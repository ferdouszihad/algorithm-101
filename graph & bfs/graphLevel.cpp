#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int level[1005];

void input(int n, int e)
{
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    while (e--)
    {
        int n1, n2;
        cin >> n1 >> n2;

        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1);
    }
}
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int node : adj_list[f])
        {
            if (!visited[node])
            {
                q.push(node);
                visited[node] = true;
                level[node] = level[f] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    input(n, e);
    bfs(0);

    int l;
    cin >> l;
    vector<int> levelNodes;

    for (int i = 0; i < 1005; i++)
    {

        if (level[i] == l)
        {
            levelNodes.push_back(i);
        }
    }

    reverse(levelNodes.begin(), levelNodes.end());

    for (int node : levelNodes)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}