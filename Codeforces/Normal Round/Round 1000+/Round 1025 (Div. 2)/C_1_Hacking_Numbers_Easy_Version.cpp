#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    auto askSum = [](ll y) {
        cout << "add " << y << endl;
        ll x;
        cin >> x;
        return x;
    };
    auto askMul = [](ll y) {
        cout << "mul " << y << endl;
        ll x;
        cin >> x;
        return x;
    };
    auto askDigitSum = []() {
        cout << "digit" << endl;
        ll x;
        cin >> x;
        return x;
    };
    ll a = askDigitSum();
    ll b = askDigitSum();
    askSum(-8);
    askSum(-4);
    askSum(-2);
    askSum(-1);
    ll ans = askMul(n);
    // cout << ans << endl;
    cout << "!" << endl;
    cin >> ans;
}

int32_t main() {
    // ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}