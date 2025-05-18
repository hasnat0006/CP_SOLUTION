#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
using namespace std;
int calc(int n, int m) {
    int cnt = 0;
    while (n > 1) {
        n = (n + 1) / 2;
        cnt++;
    }
    while (m > 1) {
        m = (m + 1) / 2, cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    ll t = 1, tc = 1;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int mn, curn, curm;
        /// vertical cut
        curn = n, curm = min(b, m - b + 1);
        mn = calc(curn, curm);

        /// horizontal cut
        curn = min(a, n - a + 1), curm = m;

        mn = min(mn, calc(curn, curm));
        cout << mn + 1 << "\n";
    }
}
