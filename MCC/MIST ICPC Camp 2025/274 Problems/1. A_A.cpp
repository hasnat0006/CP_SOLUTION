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
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll stH = (s[0] - '0') * 10 + (s[1] - '0');
        ll stM = (s[2] - '0') * 10 + (s[3] - '0');
        if (stM % 5 != 0) {
            stM = (stM / 5) * 5;
        }

        ll enH = (s[5] - '0') * 10 + (s[6] - '0');
        ll enM = (s[7] - '0') * 10 + (s[8] - '0');
        if (enM % 5 != 0) {
            enM = (enM / 5) * 5 + 5;
            if (enM == 60) {
                enM = 0;
                enH++;
            }
        }
        v.push_back({stH * 60 + stM, enH * 60 + enM});
    }
    sort(v.begin(), v.end());
    map<ll, ll> m;
    vector<ll> freq(2000, 0);

    for (auto [s, e] : v) {
        freq[s]++;
        freq[e]--;
    }

    for (int i = 1; i < 2000; i++)
        freq[i] += freq[i - 1];

    bool f = true;
    ll st = 0;
    for (int i = 0; i < 2000; i++) {
        if (freq[i] != 0 and f) {
            st = i;
            f = false;
        }
        if (freq[i] == 0 and !f) {
            f = true;
            m[st] = i;
        }
    }
    for (auto [s, e] : m) {
        ll stH = s / 60;
        ll stM = s % 60;
        ll enH = e / 60;
        ll enM = e % 60;
        cout << setfill('0') << setw(2) << stH << setfill('0') << setw(2) << stM
             << "-" << setfill('0') << setw(2) << enH << setfill('0') << setw(2)
             << enM << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}