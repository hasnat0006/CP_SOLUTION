
#include <bits/stdc++.h>

using namespace std;

#define int long long

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
    while (k > 0 and dq.size() > 1) {
        if (turn == 0) {
            int x = dq.front();
            dq.pop_front();
            x--;
            k--;
            if (x > 0)
                dq.push_front(x);
        }
        else {
            int x = dq.back();
            dq.pop_back();
            x--;
            k--;
            if (x > 0)
                dq.push_back(x);
        }
        turn = !turn;
        // print(dq);
    }
    if (dq.size() == 1) {
        if (k >= dq.front())
            dq.pop_front();
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