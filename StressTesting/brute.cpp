#ifdef DeBuG
#include "debug.h"
#else
#include <bits/stdc++.h>
#define dbg(...)
#endif
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(v) (int)(v).size()
#define all(v) begin(v), end(v)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
template <class T>
using V = vector<T>;

void solvetc(int cs) {
    int n, q;
    cin >> n >> q;
    V<int> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];

    V<int> alt(n + 2);
    alt[n] = n;
    for (int i = n - 1; i > 0; --i) {
        if (a[i] != a[i + 1])
            alt[i] = alt[i + 1];
        else
            alt[i] = i;
    }

    V<int> sum(n + 2);
    rep(i, 1, n + 1) sum[i] = sum[i - 1] + a[i];

    while (q--) {
        int l, r;
        cin >> l >> r;

        int one = sum[r] - sum[l - 1];
        int zer = (r - l + 1) - one;

        if (one % 3 != 0 || zer % 3 != 0) {
            cout << "-1\n";
            continue;
        }

        int ans = (one + zer) / 3;

        if (alt[l] >= r) {
            ++ans;
        }

        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc, cs = 1;
    cin >> tc;
    while (tc--)
        solvetc(cs++);
    return 0;
}