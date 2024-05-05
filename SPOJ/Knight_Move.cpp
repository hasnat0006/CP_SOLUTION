//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;
// #include "debug.h"
#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

using namespace std;

int visited[1000][1000];
int level[1000][1000];
vector<pair<int, int>> moves = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int getx(string s) { return s[0] - 'a'; }
int gety(string s) { return s[1] - '1'; }

bool isValid(int x, int y)
{
    return (x >= 0 and x < 1000 and y >= 0 and y < 1000);
}

void initial()
{
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            level[i][j] = visited[i][j] = 0;
}

void bfs(int x, int y)
{
    int startx = x;
    int starty = y;
    queue<pair<int, int>> q;
    q.push({startx, starty});
    visited[startx][starty] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (auto i : moves)
        {
            int cx = i.first + x;
            int cy = i.second + y;
            if (isValid(cx, cy) and !visited[cx][cy])
            {
                q.push({cx, cy});
                level[cx][cy] = level[x][y] + 1;
                visited[cx][cy] = 1;
            }
        }
    }
}
void solve()
{
    // initial();
    int a, b;
    cin >> a >> b;
    cout << level[a - 1][b - 1] << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    bfs(0, 0);
    while (t--)
        solve();
    return 0;
}