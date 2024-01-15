#include <bits/stdc++.h>
using namespace std;

struct _ {
    ios_base::Init i;
    _() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cout << fixed << setprecision(10);
    }
} ___;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set
// tree<LL,null_type,less<LL>,rb_tree_tag,tree_order_statistics_node_update>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define LL long long
#define LD long double
#define asort(ar, n) sort(ar, ar + n)
#define vsort(vc) sort(vc.begin(), vc.end())
#define vrsort(vc) sort(vc.rbegin(), vc.rend())
#define srev(st) reverse(st.rbegin(), st.rend())
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define yes cout << "yes\n"
#define no cout << "no\n"
#define Case(a) cout << "Case #" << a << ": "
#define CaseN(a) cout << "Case " << a << ":\n"
#define psum(vc, sm) partial_sum(vc.begin(), vc.end(), sm.begin() + 1)
#define pxor(vc, sm)                                  \
    partial_sum(vc.begin(), vc.end(), sm.begin() + 1, \
                [](LL x, LL y) { return x ^ y; })
#define pgcdLeft(vc, sm)                              \
    partial_sum(vc.begin(), vc.end(), sm.begin() + 1, \
                [](LL x, LL y) { return __gcd(x, y); })
#define pgcdRight(vc, sm)                               \
    partial_sum(vc.rbegin(), vc.rend(), sm.begin() + 1, \
                [](LL x, LL y) { return __gcd(x, y); })
#define pi acos(-1)

LL r, c, gr, gc;
LL X[4] = {1, -1, 0, 0};
LL Y[4] = {0, 0, 1, -1};
const LL MXX = 3e3 + 3;
string arr[MXX];
LL vis[MXX][MXX];
LL black[MXX][MXX];
LL total;

LL dfs(LL row, LL col, LL cnt) {
    vis[row][col] = cnt;

    if (arr[row][col] == '.') {
        gr = row;
        gc = col;
        return 1;
    }
    if (arr[row][col] == 'B')
        return 0;

    LL ans = 0;
    for (LL i = 0; i < 4; i++) {
        if (row + X[i] < 0)
            continue;
        if (row + X[i] >= r)
            continue;
        if (col + Y[i] < 0)
            continue;
        if (col + Y[i] >= c)
            continue;
        if (vis[row + X[i]][col + Y[i]] == cnt)
            continue;

        ans += dfs(row + X[i], col + Y[i], cnt);
    }

    total++;
    return ans;
}

int main() {
    FastIO;
    FileIO;

    LL t = 1, tc = 0, n;
    cin >> t;
    while (t--) {
        memset(vis, false, sizeof vis);

        cin >> r >> c;
        for (LL i = 0; i < r; i++) {
            cin >> arr[i];
        }

        LL cnt = 0;
        LL mxx = 0;
        for (LL i = 0; i < r; i++)
            for (LL j = 0; j < c; j++)
                if (arr[i][j] == 'W' and vis[i][j] == 0) {
                    total = 0;
                    LL tmp = dfs(i, j, ++cnt);
                    if (tmp == 1) {
                        black[gr][gc] += total;
                        mxx = max(mxx, black[gr][gc]);
                    }
                }

        Case(++tc);
        if (mxx == 0)
            NO;
        else
            YES;
    }
    return 0;
}
