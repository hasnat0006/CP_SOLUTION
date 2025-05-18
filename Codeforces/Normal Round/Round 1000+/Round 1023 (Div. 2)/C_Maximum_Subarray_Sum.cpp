#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto maximum_subarray_sum = [&]() {
        ll size = v.size();
        ll maxTill = INT_MIN, maxEnd = 0, finalMx = INT_MIN;
        for (ll i = 0; i < size; i++) {
            if (s[i] == '1') {
                maxEnd = maxEnd + v[i];
                if (maxTill < maxEnd)
                    maxTill = maxEnd;
                if (maxEnd < 0)
                    maxEnd = 0;
                finalMx = max(finalMx, maxEnd);
            }
            else 
                maxTill = INT_MIN, maxEnd = 0;
        }
        return finalMx;
    };
    // cout << "Maximum Subarray Sum: " << maximum_subarray_sum() << endl;
    if(maximum_subarray_sum() > k) {
        cout << "NO" << endl;
        return;
    }
    if(maximum_subarray_sum() == k) {
        cout << "YES" << endl;
        ll j = 0;
        while (j < n) {
            if (s[j] == '0')
                v[j] = -inf;
            j++;
        }
        for(auto i : v)
            cout << i << " ";
        cout << endl;
        return;
    }
    ll id = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            id = i;
            break;
        }
    }
    if(id == -1 and maximum_subarray_sum() != k) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ll pre = 0, presum = 0, suf = 0, sufsum = 0;
    ll i = id - 1;
    while(i >= 0 and s[i] != '0') {
        presum += v[i];
        pre = max(pre, presum);
        i--;
    }
    ll j = id + 1;
    while(j < n and s[j] != '0') {
        sufsum += v[j];
        suf = max(suf, sufsum);
        j++;
    }
    v[id] = k - pre - suf;
    j = id + 1;
    while(j < n) {
        if(s[j] == '0')
            v[j] = -inf;
        j++;
    }
    for(auto i : v)
        cout << i << " ";
    cout << endl;
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