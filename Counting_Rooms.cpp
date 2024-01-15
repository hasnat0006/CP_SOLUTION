//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define printyes cout << "YES\n";
#define printno cout << "NO\n";
#define vf(v) v.begin(), v.end()
#define vr(v) v.rbegin(), v.rend()
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int INF = 1e18;

#ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
// #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

void _print(int t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(float t) { cerr << t; }
void _print(string t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[1001][1001];

bool isValid(int x, int y, int n, int m)
{
    if (x < 0 or x >= n or y < 0 or y >= m)
        return false;
    if (visited[x][y])
        return false;
    return true;
}

void dfs(int x, int y, int n, int m)
{
    visited[x][y] = true;
    for (auto i : moves)
    {
        if (isValid(x + i.first, i.second + y, n, m))
            dfs(x + i.first, y + i.second, n, m);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << arr[i][j];
    //     cout << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
                visited[i][j] = true;
            else
                visited[i][j] = false;
        }
    }
    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j, n, m);
                rooms++;
            }
        }
    }
    // debug(moves);
    cout << rooms << endl;
    // // for(auto it:moves)

    // cout<<rooms<<endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}