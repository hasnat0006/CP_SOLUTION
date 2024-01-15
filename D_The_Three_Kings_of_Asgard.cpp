#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;
const int mod = 1e9 + 7;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m, h, z;
        int flag = 0;
        for (int i = 1; i <= 100; i++) {
            m = n + (i * 3);
            h = n - (i * 1);
            z = n - (i * 2);
            m = m - h;
            // cout<<m<<endl;
            h = h + h;
            // cout<<h<<" "<<m<<endl;
            h = h - z;
            z = z + z;
            z = z - m;
            m = m + m;
            // cout<<m<<" "<<h<<" "<<z<<endl;
            if (m == n and h == n and z == n) {
                cout << n + (i * 3) << " " << n - (i * 1) << " " << n - (i * 2)
                     << endl;
                flag = 0;
                break;
            }
            else {
                flag = 1;
            }
        }
        if (flag)
            cout << "Impossible\n";
    }
}