#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()

const ll mod = 1e9 + 7;
const ll inf = 1e18;

void solve() {
   string s;
   cin >> s;
    int n = s.size();
    map<ll, ll>freq;
    for (char c : s) {
        freq[c - 'a']++;
    }
    if(freq.size() == 1) {
        cout << "-1\n";
        return;
    }
    for(auto [i, c]: freq) {
        while(c--) {
            cout << (char)(i + 'a');
        }
    }
    cout << '\n';

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