
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const double pai = acos(-1);

int main() {
    ll nc;
    cin >> nc;
    vector<int> v[nc + 1];
    for (int i = 0; i < nc; i++) {
        ll p;
        cin >> p;
        for (int j = 0; j < p; j++) {
            ll x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    ll q;
    cin >> q;

    ll tc = 1;

    while (q--) {
        ll c1, c2;
        cin >> c1 >> c2;
        ll d, m, y;
        cin >> d >> m >> y;
        c1--;
        c2--;
        ll total1 = 0;
        ll temp1 = 0;
        for (int i = 0; i < v[c1].size(); i++) {
            total1 += v[c1][i];
            if ((i + 1) <= (m - 1)) {
                temp1 += v[c1][i];
            }
        }
        // debug(temp1);
        ll total2 = 0;

        for (int i = 0; i < v[c2].size(); i++) {
            total2 += v[c2][i];
        }
        ll tot1 = 0;
        tot1 += total1 * (y - 1) + temp1 + d;
        //! c1 er total days
        // debug(tot1);
        // debug(total2);
        ll ans = tot1 % total2;
        ll year = tot1 / total2;
        if (ans)
            year++;
        ll month;
        for (int i = 0; i < v[c2].size(); i++) {
            if (ans < v[c2][i]) {
                month = i + 1;
                break;
            }
            else {
                ans -= v[c2][i];
            }
        }
        cout << "Query " << tc << ": " << ans << " " << month << " " << year << "\n";
        tc++;
    }
}