#include <bits/stdc++.h>
#define endl "\n"
#define in long long
#define dub double
#define dubb long double
#define pb push_back
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    in i, j, k, n, c, s, f, t = 1, x;
    cin >> t;
    while (t--) {
        c = 0, f = 0, s = 0;
        cin >> n >> k;
        in a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (i = 0; i < n - 1; i++) {
            s += a[i];
        }
        s += a[n - 1];
        x = s / k;
        if (s % k)
            x++;
        x = max(x, a[n - 1]);
        cout << x << "\n";
    }
    return 0;
}
