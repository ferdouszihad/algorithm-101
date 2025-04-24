#include <bits/stdc++.h>
using namespace std;
vector<int> am[1005];
bool visited[1005] = {false};
int n, e;

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    visited[root] = false;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        //

        //

        for (int node : am[f])
        {
            if (!visited[node])
            {
                q.push(node);
                visited[node] = true;
            }
        }
    }
}

bool canVisit(int src, int end)
{

    bfs(src);

    return visited[end];
}

int main()
{

    cin >> n >> e;

    while (e--)
    {

        int n1, n2;
        cin >> n1 >> n2;
        am[n1].push_back(n2);
        am[n2].push_back(n1);
    }

    int src, end;
    cin >> src >> end;

    if (canVisit(src, end))
    {
        cout << "user can visit from " << src << " to " << end;
    }
    else
    {
        cout << "user cannot visit from " << src << "to " << end;
    }

    return 0;
}