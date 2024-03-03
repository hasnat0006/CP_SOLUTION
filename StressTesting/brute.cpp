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
} ___;
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

bool isSubArray(vector<int> &a, vector<int> &b, int i, int j) {
    // check if b[0..i] and b[j..n-1] is subsequence of a
    int n = a.size();
    int m = b.size();
    int st = 0;
    bool isSubSeq = false;
    int last = -1;
    while (st < i) {
        bool flag = false;
        for (int k = last + 1; k < n; k++) {
            if (a[k] == b[st]) {
                flag = true;
                last = k;
                break;
            }
        }
        if (!flag) {
            return false;
        }
        st++;
    }
    st = j + 1;
    while (st < m) {
        bool flag = false;
        for (int k = last + 1; k < n; k++) {
            if (a[k] == b[st]) {
                flag = true;
                last = k;
                break;
            }
        }
        if (!flag) {
            return false;
        }
        st++;
    }
    return true;
}

bool check(vector<int> &a, vector<int> &b, int x) {
    if (x == b.size())
        return true;
    for (int i = 0; i < b.size(); i++) {
        if (i + x - 1 >= b.size()) {
            break;
        }
        if (isSubArray(a, b, i, i + x - 1)) {
            return true;
        }
    }
    return false;
}

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> b(n);
    for (auto &i : b)
        cin >> i;
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // debug(mid);
        if (check(a, b, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    // cout << check(a, b, 18) << endl;
}

auto main() -> int32_t {
    IOS;
    int t = 1, cs = 1;
    // cin >> t;
    while (t--) {
        cout << "Case " << cs++ << ": ";
        solve();
    }

    return 0;
}