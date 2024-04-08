//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|04|2024 21:37:04            !//
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

void print(deque<int> dq) {
    for (auto x : dq)
        cerr << x << " ";
    cerr << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    int turn = 0;
    while (dq.size() > 1) {
        int f = dq.front();
        int b = dq.back();
        if (b < f) {
            int required = b * 2;
            if (turn == 1) {
                turn = 0;
                required--;
                if (required <= k) {
                    k -= required;
                    dq.pop_back();
                    dq.pop_front();
                    dq.push_front(f - (b - 1));
                }
                else
                    break;
            }
            else {
                if (required <= k) {
                    k -= required;
                    dq.pop_back();
                    dq.pop_front();
                    dq.push_front(f - b);
                }
                else
                    break;
            }
        }
        else {
            int required = f * 2;
            if (turn == 0) {
                turn = 1;
                required--;
                if (required <= k) {
                    k -= required;
                    dq.pop_back();
                    dq.pop_front();
                    dq.push_back(b - (f - 1));
                }
                else
                    break;
            }
            else {
                if (required <= k) {
                    k -= required;
                    dq.pop_back();
                    dq.pop_front();
                    dq.push_back(b - f);
                }
                else
                    break;
            }
        }
        // turn ^= 1;
        print(dq);
        cerr << "K: " << k << endl;
    }
    if (dq.size() == 1) {
        if (k >= dq.front())
            dq.pop_back();
    }
    cout << n - dq.size() << endl;
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