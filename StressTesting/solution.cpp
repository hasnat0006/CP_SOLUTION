//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 14|10|2024 01:53:31            !//
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

void printing(priority_queue<int> pq) {
    while (pq.size()) {
        cerr << pq.top() << " ";
        pq.pop();
    }
    cerr << endl;
}

void solve() {
    int n, x;
    cin >> n >> x;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    int ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        int sum = x * pq.top();
        // printing(pq);
        while (!pq.empty() and sum > 0) {
            if (sum - pq.top() >= 0) {
                sum -= pq.top();
                pq.pop();
            }
            else {
                int t = pq.top();
                pq.pop();
                pq.push(t - sum);
                sum = 0;
            }
        }
        // printing(pq);
    }
    cout << ans << endl;
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