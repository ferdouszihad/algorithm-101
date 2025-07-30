
#include <bits/stdc++.h>
using namespace std;
bool visited[1000] = {false};
int label[1000];
vector<int> adj_list[1000];
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    visited[root] = true;
    label[root] = 0;
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
                label[node] = label[f] + 1;
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
    int src, dest;
    cin >> src >> dest;
    memset(label, -1, sizeof(label));
    memset(visited, false, sizeof(visited));
    bfs(src);

    cout << endl
         << label[dest] << endl;
    return 0;
}