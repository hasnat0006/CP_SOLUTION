/*******************************************
 @b |I|s|t|i|a|q|u|e| |A|h|m|e|d| |A|r|i|k|
********************************************/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define static_assert(...) ;
#include <tr2/dynamic_bitset>
using u_bitset = tr2::dynamic_bitset<__uint128_t>;
using l_bitset = tr2::dynamic_bitset<__int128_t>;
void __print(int x) { cerr << x; }
#define bigll __int128_t
#define bigull __uint128_t
#define ll int_fast64_t
#define ull uint_fast64_t
#define ld long double
#define pi acos(-1)
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

template <typename p, typename q>
using ht = gp_hash_table<p, q>;

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

const int MX = 1e7 + 5;
vector<int> spf(MX, 0);

void spf_pre() {
    for (int i = 2; i < MX; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < MX; j += i) {
                spf[j] = i;
            }
        }
    }
}

void fac(vector<int> &a, vector<int> &cnt) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j > 1; j /= spf[j]) {
            cnt[spf[j]]++;
        }
    }
}

void cntt(vector<int> &a, vector<int> &cnt) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int st = 1;
        for (int j = a[i]; j > 1; j /= spf[j]) {
            if (cnt[spf[j]] == 0) {
                st *= spf[j];
            }
            else {
                cnt[spf[j]]--;
            }
        }
        cout << st << " ";
    }
    cout << "\n";
}

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    spf_pre();
    vector<int> cnt(MX, 0), cnt1(MX, 0);
    // debug(spf);
    fac(a, cnt);
    fac(b, cnt1);
    cout << n << " " << m << "\n";
    cntt(a, cnt1);
    cntt(b, cnt);
}

auto main() -> int32_t {
    IOS;
    int t = 1, cs = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}