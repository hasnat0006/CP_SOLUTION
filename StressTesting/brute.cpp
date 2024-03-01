#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k, i, j, mn, z, y;
        cin >> n >> k;
        vector<int> a(n), b;
        for (int &x : a)
            cin >> x;

        if (k == 1) {
            sort(a.begin(), a.end());
            for (i = 1; i < n; i++)
                a.push_back(a[i] - a[i - 1]);
            cout << *min_element(a.begin(), a.end()) << endl;
        }
        else if (k == 2) {
            sort(a.begin(), a.end());
            mn = a[0];
            for (i = 1; i < n; i++) {
                z = a[i] - a[i - 1];
                mn = min(mn, z);
            }

            for (i = 0; i < n; i++) {
                for (j = i + 1; j < n; j++) {
                    z = abs(a[i] - a[j]);
                    b.push_back(z);
                }
            }

            for (i = 0; i < b.size(); i++) {
                z = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
                if (z == n) {
                    y = abs(b[i] - a[z - 1]);
                    mn = min(mn, y);
                }
                else if (z == 0) {
                    y = abs(b[i] - a[z]);
                    mn = min(mn, y);
                }
                else {
                    y = abs(b[i] - a[z]);
                    mn = min(mn, y);
                    y = abs(b[i] - a[z - 1]);
                    mn = min(mn, y);
                }
            }
            cout << mn << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}