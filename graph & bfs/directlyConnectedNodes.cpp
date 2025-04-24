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

    int node, dc = 0;
    cin >> node;
    cout << adj_list[node].size() << endl;

    return 0;
}