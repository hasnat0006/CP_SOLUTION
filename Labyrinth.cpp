//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

// #define int long long
// #define float long double
#define pb push_back
#define pairi pair<int, int>
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
// int inf = 1e18;

int n, m;
pairi st, ed;
char arr[1000][1000];
int visited[1000][1000];
string des[1000][1000];
map<pairi, pairi> parent, level;
vector<pairi> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y)
{
    return (x >= 0 and x < n and y >= 0 and y < m);
}

string jabe(pairi a, pairi b)
{
    int x1 = a.first, y1 = a.second, x2 = b.first, y2 = b.second;
    if (x1 == x2)
    {
        if (y1 > y2)
            return "R";
        return "L";
    }
    else if (y1 == y2)
    {
        if (x1 > x2)
            return "D";
        return "U";
    }
}

void bfs(pairi start)
{
    queue<pairi> q;
    q.push(start);
    while (!q.empty())
    {
        pairi k = q.front();
        q.pop();
        visited[k.first][k.second] = 1;
        for (auto it : moves)
        {
            int x = k.first + it.first;
            int y = k.second + it.second;
            if (isValid(x, y) and !visited[x][y])
            {
                // cout << "x y : " << k.first << " " << k.second << " -> " << x << " " << y << endl;
                des[x][y] = jabe({x, y}, k);
                q.push({x, y});
                parent[{x, y}] = k;
                if (visited[ed.first][ed.second])
                    return;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '#')
                visited[i][j] = 2;
            else if (arr[i][j] == 'A')
                st = {i, j};
            else if (arr[i][j] == 'B')
                ed = {i, j};
        }
    }
    bfs(st);
    if (!visited[ed.first][ed.second])
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    // debug(parent);
    vector<string> ans;
    while (ed != st)
    {
        ans.pb(des[ed.first][ed.second]);
        ed = parent[ed];
    }
    reverse(vf(ans));
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it;
    cout << endl;
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