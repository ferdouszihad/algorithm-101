#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];

void dfs(int src)
{

    visited[src] = true;
    cout << src << "-->";
    for (int node : adj_list[src])
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
        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1);
    }
    memset(visited, false, sizeof(visited));
    dfs(1);
    cout << endl
         << endl;

    for (int i = 0; i < n; i++)
    {

        cout << i << " is connected with -> ";
        for (int node : adj_list[i])
        {
            cout << node << " , ";
        }
        cout << endl;
    }

    return 0;
}