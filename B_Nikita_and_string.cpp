//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false);
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 200000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int visited[20][20];
int v[20][20];
pair<int, int> start, last;
int c = 0;
vector<string> ans;
int n, m;
bool isValid(int x, int y)
{
    if (x >= 0 and x < n and y >= 0 and y < m)
        return true;
    return false;
}

void dfs(pair<int, int> start)
{
    visited[start.first][start.second] = 1;
    for (int i = 0; i < 4; i++)
    {
        int x = start.first + dx[i];
        int y = start.second + dy[i];
        if (isValid(x, y) and !visited[x][y] and v[x][y])
        {
            // cout << start.first << " " << start.second << " -> " << x << " " << y << endl;
            if (y > start.second)
                ans.pb("right");
            else if (x < start.first)
                ans.pb("forth");
            else
                ans.pb("left");
            // debug(ans);
            if (x == last.first and y == last.second)
                return;
            dfs({x, y});
        }
    }
}

void initial()
{
    last.first = last.second = start.first = start.second = 0;
    c = 0;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            v[i][j] = visited[i][j] = 0;
    ans.clear();
}

void solve()
{
    initial();
    cin >> n >> m;
    map<char, int> in;
    // IEHOVA
    string s = "IEHOVA";
    for (auto i : s)
        in[i] = 1;
    // debug(in);
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            if (in[ch])
                v[i][j] = 1;
            else if (ch == '@')
                v[i][j] = 1, start.first = i, start.second = j;
            else if (ch == '#')
                v[i][j] = 1, last.first = i, last.second = j;
        }
    }
    dfs(start);
    // debug(ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << " ";
    }
    cout << endl;
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
