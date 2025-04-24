#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool visited[100005];
int level[100005];
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

        for (int n : adj_list[f])
        {
            if (!visited[n])
            {
                q.push(n);
                visited[n] = true;
                level[n] = level[f] + 1;
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

    int q;
    cin >> q;
    while (q--)
    {
        int src, dest;
        cin >> src >> dest;
        memset(visited, false, sizeof(visited));
        memset(level, -1, sizeof(level));
        bfs(src);
        cout << level[dest] << endl;
    }

    return 0;
}