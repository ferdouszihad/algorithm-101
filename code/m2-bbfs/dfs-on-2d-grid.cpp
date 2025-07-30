#include <bits/stdc++.h>
using namespace std;
bool grid[1000][1000];
int dist[1000][1000];
pair<int, int> path[1000][1000];
pair<int, int> pos[] = {
    {-1, 0},
    {0, 1},
    {0, -1},
    {1, 0}};
int row, col;
bool validMove(int i, int j)
{
    return i >= 0 & j >= 0 && i < row && j < col;
}
void dfs(int i, int j)
{

    cout << i << j << " -->";
    grid[i][j] = true;

    for (pair<int, int> node : pos)
    {
        int new_i = i + node.first;
        int new_j = j + node.second;
        if (!grid[new_i][new_j] && validMove(new_i, new_j))
        {
            dfs(new_i, new_j);
        }
    }
}

void bfs(int i, int j)
{

    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = true;
    dist[i][j] = 0;
    // path[i][j] = {4, 2};
    while (!q.empty())
    {

        pair<int, int> f = q.front();
        q.pop();
        ////////////////////////

        cout << f.first << f.second << " → ";
        ////////////////////////

        for (pair<int, int> p : pos)
        {

            int ci = f.first + p.first;
            int cj = f.second + p.second;

            if (!grid[ci][cj] && validMove(ci, cj))
            {

                q.push({ci, cj});
                grid[ci][cj] = true;
                dist[ci][cj] = dist[f.first][f.second] + 1;
                path[ci][cj] = {f.first, f.second};
            }
        }
    }
}
int main()
{

    cin >> row >> col;
    pair<int, int> src;
    cin >> src.first >> src.second;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << i << j << " ";
        }
        cout << endl;
    }
    cout << "Visiting ----------------|" << endl;
    memset(grid, false, sizeof(grid));
    memset(dist, -1, sizeof(dist));
    memset(path, -1, sizeof(path));
    // dfs(src.first, src.second);
    bfs(src.first, src.second);
    cout << "Done🚶‍♂️‍➡️" << endl;
    cout << "--------------------" << endl;

    int end_i, end_j;
    cin >> end_i >> end_j;

    cout << "Shortest Distance = " << dist[end_i][end_j] << endl;
    cout << "--------------------" << endl;
    int i = end_i, j = end_j;

    while (i > 0 && j > 0)
    {
        cout << i << j << " ← ";
        i = path[i][j].first;
        j = path[i][j].second;
    }

    return 0;
}