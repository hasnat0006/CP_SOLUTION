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
#define ll long long
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

///@b PBDS

inline void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(rall(a));
    ll low = 0, high = 1e18, ans = 0;
    while (low <= high) {
        ll mid = low + (high - low) / 2ll;
        ll need = mid + n - 1ll;
        ll first = (need % n == 0) ? need / n : ((need / n) + 1ll);
        // debug(mid, need, low, high, first);
        ll cp = k;
        ll st = 0;
        for (ll i = 0; i < (need % n); i++) {
            if (a[i] < ((need / n) + 1ll)) {
                cp -= (((need / n) + 1ll) - a[i]);
            }
        }
        for (ll i = need % n; i < n; i++) {
            if (a[i] < (need / n)) {
                cp -= ((need / n) - a[i]);
            }
        }
        if (cp < 0) {
            high = mid - 1;
        }
        else {
            ans = mid;
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}

auto main() -> int32_t {
    IOS;
    int t = 1, cs = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}