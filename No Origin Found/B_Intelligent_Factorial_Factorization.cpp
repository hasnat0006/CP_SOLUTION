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
    map<int, int> mp;

    auto factor = [](int n) {
        if (n % 2 == 0)
            return 2;
        if (n % 3 == 0)
            return 3;
        for (int i = 5; i * i <= n; i += 2)
            if (n % i == 0)
                return i;
        return n;
    };

    for (int i = 2; i <= n; i++) {
        int num = i;
        while (num > 1) {
            ll fact = factor(num);
            while (num % fact == 0) {
                mp[fact]++;
                num /= fact;
            }
        }
    }
    cout << n << " = ";
    ll cnt = mp.size(), i = 0;
    for (auto [a, b] : mp) {
        i++;
        cout << a << " (" << b << ")" << (i < cnt ? " * " : "");
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}