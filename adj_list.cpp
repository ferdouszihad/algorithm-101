#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> edj;

    for (int i = 0; i < e; i++)
    {

        int n1, n2;
        cin >> n1 >> n2;

        edj.push_back({n1, n2});
    }

    for (pair<int, int> n : edj)
    {

        cout << n.first << "→←" << n.second << endl;
    }

    return 0;
}