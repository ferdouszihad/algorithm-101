#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005] = {false};
int level[1005] = {0};
int parent[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {

        int curr = q.front();
        q.pop();
        //

        // cout << curr << " ";

        //

        for (int child : adj_list[curr])
        {
            if (!visited[child])
            {

                q.push(child);
                visited[child] = true;
                level[child] = level[curr] + 1;
                parent[child] = curr;
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
    int src, end;
    cin >> src >> end;
    memset(parent, -1, sizeof(parent));
    bfs(src);

    int currNode = end;
    vector<int> path;

    while (currNode != -1)
    {

        path.push_back(currNode);
        currNode = parent[currNode];
    }

    reverse(path.begin(), path.end());
    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}