#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj[n];

    for (int i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for (int i = 0; i < n; i++)
    {

        cout << i << " Connected with : ";

        for (int n : adj[i])
        {

            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}