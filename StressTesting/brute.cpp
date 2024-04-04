
/*******************************************
 @b |I|s|t|i|a|q|u|e| |A|h|m|e|d| |A|r|i|k|
********************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
void __print(int x) { cerr << x; }
#define int long long
#define pi acos(-1)
#define endl '\n'
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define FileIO                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
///@b decltype and const
const int MOD = 1e9 + 7, dx[] = {1, 0, -1, 0, 1, -1, -1, 1},
          dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
///@b debug
struct _ {
    ios_base::Init i;
    _() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cout << fixed << setprecision(10);
    }
} _;
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

///@b PBDS
// template <typename T>
// using o_set = tree<T, null_type, less<T>, rb_tree_tag,
// tree_order_statistics_node_update>; template <typename T> using o_set_g =
// tree<T, null_type, greater<T>, rb_tree_tag,
// tree_order_statistics_node_update>; template <typename T> using o_multiset =
// tree<T, null_type, less_equal<T>, rb_tree_tag,
// tree_order_statistics_node_update>; template <typename T> using o_multiset_g
// = tree<T, null_type, greater_equal<T>, rb_tree_tag,
// tree_order_statistics_node_update>;

int cnt(int st, string &s) {
    bool hasR = false, hasG = false, hasB = false;
    for (int i = st - 2; i <= st; i++) {
        if (s[i] == 'R')
            hasR = true;
        if (s[i] == 'G')
            hasG = true;
        if (s[i] == 'B')
            hasB = true;
    }
    return hasR + hasG + hasB;
}

int cntSep(string &s, int a, int b, int c) {
    if (a == b or b == c or a == c or a >= s.size() or b >= s.size() or
        c >= s.size() or a < 0 or b < 0 or c < 0)
        return 0;
    bool hasR = false, hasG = false, hasB = false;
    if (s[a] == 'R')
        hasR = true;
    if (s[a] == 'G')
        hasG = true;
    if (s[a] == 'B')
        hasB = true;

    if (s[b] == 'R')
        hasR = true;
    if (s[b] == 'G')
        hasG = true;
    if (s[b] == 'B')
        hasB = true;

    if (s[c] == 'R')
        hasR = true;
    if (s[c] == 'G')
        hasG = true;
    if (s[c] == 'B')
        hasB = true;
    return hasR + hasG + hasB;
}

inline void solve() {
    string s;
    cin >> s;
    if (s.size() == 3) {
        cout << 0 << endl;
        return;
    }
    if (cnt(2, s) == 3 or cnt(s.size() - 1, s) == 3) {
        cout << 1 << endl;
        return;
    }
    if (cntSep(s, 0, s.size() - 1, s.size() - 2) == 3 or
        cntSep(s, 0, 1, s.size() - 1) == 3) {
        cout << 2 << endl;
        return;
    }
    for (int i = 3; i < s.size() - 1; i++) {
        if (cnt(i, s) == 3) {
            cout << 2 << endl;
            return;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (cntSep(s, i, i + 1, 0) == 3) {
            cout << 3 << endl;
            return;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (cntSep(s, i, i + 1, s.size() - 1) == 3) {
            cout << 3 << endl;
            return;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (cntSep(s, 0, 1, i) == 3) {
            cout << 3 << endl;
            return;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (cntSep(s, i, s.size() - 1, s.size() - 2) == 3) {
            cout << 3 << endl;
            return;
        }
    }
    cout << 4 << endl;
}

auto main() -> int32_t {
    IOS;
    int t = 1, cs = 1;
    while (t--) {
        solve();
    }

    return 0;
}