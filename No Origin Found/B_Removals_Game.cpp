//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 11|08|2024 20:52:12            !//
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    deque<int> A, B;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        A.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        B.push_back(b[i]);
    }
    while (A.size()) {
        int Afirst = A.front();
        int Alast = A.back();
        int Bfirst = B.front();
        int Blast = B.back();
        if (Afirst == Bfirst and Alast == Blast) {
            A.pop_front();
            B.pop_front();
        }
        else if (Afirst == Blast and Alast == Bfirst) {
            A.pop_front();
            B.pop_back();
        }
        else {
            cout << "Alice" << endl;
            return;
        }
    }
    cout << "Bob" << endl;
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