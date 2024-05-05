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

int visited[8][8];
int level[8][8];
vector<pair<int, int>> moves = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int getx(string s) { return s[0] - 'a'; }
int gety(string s) { return s[1] - '1'; }

bool isValid(int x, int y)
{
    return (x >= 0 and x < 8 and y >= 0 and y < 8);
}

void initial()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            level[i][j] = visited[i][j] = 0;
}

int bfs(string start, string end)
{
    int startx = getx(start);
    int starty = gety(start);
    int endx = getx(end);
    int endy = gety(end);
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
    return level[endx][endy];
}
void solve()
{
    initial();
    string a, b;
    cin >> a >> b;
    cout << bfs(a, b) << endl;
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //         cout << level[i][j] << " ";
    //     cout << endl;
    // }
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}