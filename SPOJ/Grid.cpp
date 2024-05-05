//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
//#include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

int arr[501][501];
int visited[501][501];
int level[501][501];
int n, m;

vector<pair<int, int>> moves = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

bool isValid(int x, int y) { return (x > 0 and x <= n and y > 0 and y <= m); }

void bfs(int xx, int yy)
{
    queue<pair<int, int>> q;
    q.push({xx, yy});
    visited[xx][yy] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (auto i : moves)
        {
            int cx = (arr[x][y] * i.first) + x;
            int cy = (arr[x][y] * i.second) + y;
            // if (arr[cx][cy] == 0)
            //     continue;
            if (isValid(cx, cy) and !visited[cx][cy])
            {
                // cout << "x y : " << x << " " << y << " -> " << cx << " " << cy << endl;
                q.push({cx, cy});
                level[cx][cy] = level[x][y] + 1;
                visited[cx][cy] = 1;
            }
        }
    }
}

void solve()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            arr[i + 1][j + 1] = s[j] - '0';
    }
    bfs(1, 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << level[i][j] << " ";
    //     cout << endl;
    // }
    if (!level[n][m])
        cout << "-1\n";
    else
        cout << level[n][m] << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}