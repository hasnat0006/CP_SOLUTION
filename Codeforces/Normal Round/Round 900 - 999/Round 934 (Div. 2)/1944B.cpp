//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 16|03|2024 21:07:12            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x]++;
    }
    vector<int> ansA, ansB;
    int cnt = 0;
    for (auto &i : a) {
        if (i.second > 1) {
            ansA.push_back(i.first);
            ansA.push_back(i.first);
            // a.erase(a.find(i.first));
            a[i.first] -= 2;
            cnt += 2;
        }
    }
    for (auto &i : b) {
        if (i.second > 1) {
            ansB.push_back(i.first);
            ansB.push_back(i.first);
            // b.erase(b.find(i.first));
            b[i.first] -= 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] and b[i]) {
            ansA.push_back(i);
            ansB.push_back(i);
            cnt++;
        }
    }
    for (int i = 0; i < 2 * k; i++)
        cout << ansA[i] << " ";
    cout << endl;
    for (int i = 0; i < 2 * k; i++)
        cout << ansB[i] << " ";
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