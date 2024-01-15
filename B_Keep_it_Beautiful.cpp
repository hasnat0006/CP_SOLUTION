//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;

#define int   long long
#define float long double
#define pb    push_back
#define printyes cout << "YES\n";
#define printno cout << "NO\n";
#define vf(v) v.begin(), v.end()
#define vr(v) v.rbegin(), v.rend()
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF  ios_base::sync_with_stdio(false),
#define REZA   cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int INF = 1e18;

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

void _print(int t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(float t) {cerr << t;}
void _print(string t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    fl(i, n)
            cin >>
        v[i];
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    if (is_sorted(v.begin(), v.end()))
    {
        while (n--)
            cout << "1";
        cout << endl;
        return;
    }
    vector<int> temp;
    bool f = true;
    temp.pb(v[0]);
    temp.pb(v[1]);
    int mx = max(v[0], v[1]);
    if (mx == v[0])
        f = false;
    string s = "11";
    for (int i = 2; i < n; i++)
    {
        if (v[i] >= mx and f)
        {
            temp.pb(v[i]);
            s.pb('1');
            mx = max(mx, v[i]);
        }
        else if (v[i] <= temp.front() and v[i] >= temp.back())
        {
            temp.pb(v[i]);
            s.pb('1');
            mx = max(mx, v[i]);
        }
        else if (f and v[i] <= v.front())
        {
            temp.pb(v[i]);
            s.pb('1');
            f = false;
        }
        else
            s.pb('0');
        // debug(temp);
    }
    cout << s << endl;
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