#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];
    while (e--)
    {

        int n1, n2;
        cin >> n1 >> n2;

        adj_list[n1].push_back(n2);
        adj_list[n2].push_back(n1);
    }

    for (int i = 0; i < n; i++)
    {

        cout << i << " is connected with ";

        for (int node : adj_list[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}