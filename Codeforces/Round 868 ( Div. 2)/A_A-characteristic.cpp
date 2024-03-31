//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;
int everything(int p) { return (p * (p - 1) / 2); }

void solve() {
    map<int, int> index;
    int n, k;
    cin >> n >> k;
    for (int i = n; i >= n / 2; i--) {
        index[everything(i) + everything(n - i)] = i;
    }
    if (index[k] > 0) {
        cout << "YES\n";
        for (int i = 0; i < index[k]; i++)
            cout << "1 ";
        for (int i = index[k]; i < n; i++)
            cout << "-1 ";
        cout << endl;
    }
    else
        cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}