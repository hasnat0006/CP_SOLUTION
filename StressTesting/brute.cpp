#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define nl << "\n"
#define pi acos(-1)
#define pb push_back
#define vec2d(name, n, m, val) \
    vector<vector<int>>(name)((n), vector<int>((m), (val)))
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define l_b lower_bound
#define u_b upper_bound
#define F first
#define S second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define ok cout << "ok" nl
#define Case(t) cout << "Case " << t << ":\n"
#define setpre(n) fixed << setprecision(n)
#define input(x)      \
    for (auto &i : x) \
    cin >> i
#define print(x)          \
    for (auto &i : x)     \
        cout << i << " "; \
    cout nl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, T = 1;
    cin >> T;
    for (t = 1; t <= T; t++) {
        lli n, k, q;
        cin >> n >> k >> q;
        lli a[k + 1], b[k + 1];
        a[0] = b[0] = 0;
        for (lli i = 1; i <= k; i++)
            cin >> a[i];
        for (lli i = 1; i <= k; i++)
            cin >> b[i];
        while (q--) {
            lli d;
            cin >> d;
            lli id = u_b(a, a + k + 1, d) - a - 1;
            if (a[id] == d)
                cout << b[id] << " ";
            else {
                cout << b[id] + ((b[id + 1] - b[id]) * (d - a[id])) /
                                    (a[id + 1] - a[id])
                     << " ";
            }
        }
        cout nl;
    }
    return 0;
}