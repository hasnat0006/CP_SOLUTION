//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|11|2024 12:33:32            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll   long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

const ll N = 1e7 + 5;
ll spf[N];
void smallestPrimeFactorUsingSeive() {
    for (ll i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (ll j = i; j < N; j += i) {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

ll calculate(ll l, ll r, ll x){
    vector<ll> v;
    while(x != 1){
        ll temp = spf[x];
        v.push_back(temp);
        while(x % temp == 0)
            x /= temp;
    }
    ll ans = r - l + 1;
    for(ll mask = 1; mask < (1 << v.size()); mask++){
        ll cnt = 0, mul = 1;
        for(ll i = 0; i < v.size(); i++){
            if(mask & (1 << i)){
                cnt++;
                mul *= v[i];
            }
        }
        if(cnt & 1)
            ans -= r / mul - (l - 1) / mul;
        else
            ans += r / mul - (l - 1) / mul;
    }
    return ans;
}

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans1 = 0;
    for(ll i = a; i <= b; i++){
        ans1 += calculate(c, d, i);
    }
    ll ans2 = 0;
    for(ll i = c; i <= d; i++){
        ans2 += calculate(a, b, i);
    }
    cout << max(ans1, ans2) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    smallestPrimeFactorUsingSeive();
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(); 
    }
    return 0;
}