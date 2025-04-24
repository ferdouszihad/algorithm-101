#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_matrix[n][n];
    memset(adj_matrix, 0, sizeof(adj_matrix));

    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj_matrix[n1][n2] = 1;
        adj_matrix[n2][n1] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_matrix[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}