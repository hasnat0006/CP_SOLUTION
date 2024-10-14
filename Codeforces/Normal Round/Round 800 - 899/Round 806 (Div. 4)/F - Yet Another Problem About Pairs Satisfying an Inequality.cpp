//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;

void unsolve() {
    int n, c = 0;
    cin >> n;
    vector<int> value, id;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= i) {
            value.pb(x);
            id.pb(i + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < value.size(); i++) {
        ans += lower_bound(id.begin(), id.end(), value[i]) - id.begin();
    }
    cout << ans << "\n";
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