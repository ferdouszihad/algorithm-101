#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int am[n][m];

    // shortcut of setting a value in 2D array
    memset(am, 0, sizeof(am));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                am[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << am[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {

        int nodeA, nodeB;
        cin >> nodeA >> nodeB;

        am[nodeA][nodeB] = 1;
        am[nodeB][nodeA] = 1;
    }

    cout << "======================\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << am[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}