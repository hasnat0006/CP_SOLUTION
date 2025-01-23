#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

class Node {
   public:
    ll evenNum, evenCnt, oddNum, oddCnt;
    Node() { evenNum = evenCnt = oddNum = oddCnt = 0; }
    Node(ll a, ll b, ll c, ll d) {
        evenNum = a, evenCnt = b, oddNum = c, oddCnt = d;
    }
    void setValue(ll a, ll b, ll c, ll d) {
        evenNum = a, evenCnt = b, oddNum = c, oddCnt = d;
    }
    void print() { dbg(evenNum, evenCnt, oddNum, oddCnt); }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    multiset<ll> a, b;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }

    function<bool(ll)> isPossible =[&] (ll num) -> bool{
        auto it = a.find(num);
        if(it != a.end()) {
            a.erase(it);
            return true;
        }
        if(num == 1)
            return false;
        ll n1 = num / 2, n2 = num - n1;
        return (isPossible(n1) and isPossible(n2));
    };

    for(auto i : b) {
        if(!isPossible(i)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << (a.empty() ? "YES" : "NO") << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}