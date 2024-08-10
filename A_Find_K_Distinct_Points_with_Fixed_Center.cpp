//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 10|08|2024 20:39:28            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

bool check(vector<pair<int, int>> &v, int x, int y, int k) {
    int sumX = 0, sumY = 0;
    for (auto i : v) {
        sumX += i.first;
        sumY += i.second;
    }
    cerr << sumX << " " << sumY << " " << k << " " << sumX / k << " "
         << sumY / k << endl;
    return (sumX / k == x && sumY / k == y);
    return false;
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int K = k;
    vector<pair<int, int>> v;
    v.push_back({k * x, k * y});
    if (k % 2 == 0) {
        if (x == 0 && y == 0) {
            v.pop_back();
            v.push_back({-1e9, -1e9});
            v.push_back({1e9, 1e9});
            k -= 2;
        }
        else {
            v.push_back({0, 0});
            k--;
        }
    }
    for (int i = 1; i <= k / 2; i++) {
        int num1 = (K * x) + i;
        int num2 = (K * y) + i;
        v.push_back({-num1, -num2});
        v.push_back({+num1, +num2});
    }
    for (auto i : v) {
        cout << i.first << " " << i.second << endl;
    }
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