#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {

            adj[i][j] = 0;
            if (i == j)
                adj[i][j] = 1;
        }

    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}