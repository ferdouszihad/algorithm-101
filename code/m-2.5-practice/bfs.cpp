#include <bits/stdc++.h>
using namespace std;
bool visited[1000] = {false};
vector<int> adj_list[1000];
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while (!q.empty())
    {

        int f = q.front();
        q.pop();

        cout << f << " --> ";

        for (int node : adj_list[f])
        {

            if (!visited[node])
            {
                q.push(node);
                visited[node] = true;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;

    int n1, n2;
    while (cin >> n1 >> n2)
    {

        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1);
    }
    bfs(10);

    return 0;
}