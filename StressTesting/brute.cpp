#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        long long a, aa, b, bb, r, i, d, f = 0;
        cin >> a >> b >> r;
        aa = a, bb = b;
        vector<bool> x(64), y(64), z(64);
        for (i = 0; i < 64; i++) {
            if (aa % 2)
                x[i] = true;
            aa /= 2;
            if (bb % 2)
                y[i] = true;
            bb /= 2;
            if (r % 2)
                z[i] = true;
            r /= 2;
        }
        for (i = 63; i >= 0; i--) {
            if (z[i] && f == 0)
                f = 1;
            if (x[i] != y[i] && f >= 1) {
                d = ((long long)(pow(2, i) + 1e-9)) * 2;
                if (x[i] == 0) {
                    if (a < b && (z[i] == 1 || f == 2) && abs(a - b) >= d) {
                        a += (long long)(pow(2, i) + 1e-9);
                        b -= (long long)(pow(2, i) + 1e-9);
                    }
                    else if (z[i] == 1)
                        f = 2;
                }
                else {
                    if (a > b && (z[i] == 1 || f == 2) && abs(a - b) >= d) {
                        a -= (long long)(pow(2, i) + 1e-9);
                        b += (long long)(pow(2, i) + 1e-9);
                    }
                    else if (z[i] == 1)
                        f = 2;
                }
            }
            else if (z[i] == 1)
                f = 2;
        }
        cout << abs(a - b) << "\n";
    }

    return 0;
}