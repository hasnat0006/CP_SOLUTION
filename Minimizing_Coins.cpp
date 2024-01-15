//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case #" << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    sort(vf(v));
    if (n == 5) {
        // cout << (float)(v[4] + v[2]) / 2.0 << " " << (float)(v[0] +  v[1])
        // / 2.0 << endl;
        if ((v[2] - v[1]) < (v[3] - v[2]))
            cout << ((float)(v[4] + v[3]) / 2.0 - (float)(v[0] + v[2]) / 2.0)
                 << endl;
        else
            cout << ((float)(v[4] + v[2]) / 2.0 - (float)(v[0] + v[1]) / 2.0)
                 << endl;
        return;
    }
    float ans =
        ((float)(v[n - 1] + v[n - 2]) / 2.0 - (float)(v[0] + v[1]) / 2.0);
    cout << dosomic(6) << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        case(i),    solve(); 
    return 0;
}