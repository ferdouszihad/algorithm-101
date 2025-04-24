#include <bits/stdc++.h>
using namespace std;
vector<int> am[1005];
bool visited[1005] = {false};
int n, e;

int sumAllNodes(int root)
{
    int sum = 0;

    queue<int> q;
    q.push(root);
    visited[root] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        //

        cout << f << "+";
        sum += f;

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
    cout << " = " << endl;
    return sum;
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

    for (int i = 0; i < n; i++)
    {

        cout << i << " connected to -> ";
        for (int node : am[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    cout << "sum of all Nodes " << sumAllNodes(4);

    return 0;
}