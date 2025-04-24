#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edj_list;
    while (e--)
    {

        int n1, n2;
        cin >> n1 >> n2;

        edj_list.push_back({n1, n2});
    }

    for (pair<int, int> p : edj_list)
    {
        cout << "{" << p.first << "," << p.second << "}" << endl;
    }

    return 0;
}