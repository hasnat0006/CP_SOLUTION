//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve() {
    int n, d;
    cin >> n >> d;
    if (n >= d)
        cout << "YES\n";
    else {
        for (int i = n; i >= 1; i--) {
            int x = 0;
            x = i + (d / (i + 1));
            if ((d % (i + 1)) != 0)
                x++;
            if (x == n) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        unsolve();
    return 0;
}