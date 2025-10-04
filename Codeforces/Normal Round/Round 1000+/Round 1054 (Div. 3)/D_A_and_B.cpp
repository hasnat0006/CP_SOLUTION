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
    string s;
    cin >> s;
    ll ans = inf;
    vector<ll> A, B;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            A.push_back(i);
        else
            B.push_back(i);
    }

    // case 0 - already valid
    // case 1 - aaaabbbb
    ll cnt = 0;
    for (int i = 0; i < A.size(); i++) {
        cnt += (A[i] - i);
    }
    ans = min(ans, cnt);
    // case 2 - bbbbaaaa
    cnt = 0;
    for (int i = 0; i < B.size(); i++) {
        cnt += (B[i] - i);
    }
    ans = min(ans, cnt);

    // case 3 - aaabbbaaa
    cnt = 0;
    ll f = 0;
    for (int i = 0; i < A.size(); i++) {
        ll leftCost = inf, rightCost = inf;
        if (!f)
            leftCost = (A[i] - i);
        rightCost = (n - 1 - A[i]);
        rightCost = rightCost - (A.size() - (i + 1));
        if (rightCost <= leftCost)
            f = 1;
        cnt += min(leftCost, rightCost);
    }
    ans = min(ans, cnt);
    // case 3 - aaabbbaaa
    cnt = 0, f = 0;
    for (int i = 0; i < B.size(); i++) {
        ll leftCost = inf, rightCost = inf;
        if (!f)
            leftCost = (B[i] - i);
        rightCost = (n - 1 - B[i]);
        rightCost = rightCost - (B.size() - (i + 1));
        if (rightCost <= leftCost)
            f = 1;
        cnt += min(leftCost, rightCost);
    }
    ans = min(ans, cnt);
    cout << ans << '\n';
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