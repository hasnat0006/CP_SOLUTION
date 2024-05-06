#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define nl "\n"
#define printa(a, L, R)         \
    for (int i = L; i < R; i++) \
    cout << a[i] << (i == R - 1 ? '\n' : ' ')
#define pb push_back
#define UB upper_bound
#define LB lower_bound
#define F first
#define S second
#define mem(a, x) memset(a, x, sizeof(a))
void __print(ll x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
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
    ll f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << ""; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
void _print(ll t) { cerr << t; }
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
void _print(pair<T, V> p) {
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
template <class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
template <class T>
void _print(multiset<T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
template <class T, class V>
void _print(map<T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}

#define debug(x...)                 \
    cerr << "[ " << #x << " ] = ["; \
    _print(x);                      \
    cerr << " ]" << endl;
ll cs;
#define _case cout << "Case #" << ++cs << ": "
#define rev(v) reverse(v.begin(), v.end())
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define dosomic(x) fixed << setprecision(x)
const ll infi = 1e18;
const ll mod = 1e9 + 7;
const ll N = 1e5 + 3;
float pi = acos(-1);
// ll dx[]={1,0,-1,0,1,-1,-1,1};
// ll dy[]={0,1,0,-1,1,1,-1,-1};
ld binaryExp(ld base, ld power) {
    ld res = 1;
    while (power) {
        if (power == 0)
            res = (res * base);
        base = ((base) * (base));
        power /= 2;
    }
    return res;
}
ld power(ld a, ll b) {
    ld res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    _case;
    ll u, v;
    cin >> u >> v;
    ll l = 1, r = 1e18, mid, ans = -1;
    while (l < r) {
        // debug(l, r);
        mid = l + (r - l) / 2;
        int kh = u * (1 - power(0.5, mid)) * 2;
        int ko = v * mid;
        if (ko > kh) {
            ans = mid;
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    // cin.ignore();
    while (t--) {
        solve();
    }
    return 0;
}