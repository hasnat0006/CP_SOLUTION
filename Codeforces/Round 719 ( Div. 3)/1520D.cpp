//!................  CG o nai CP o nai :)  ................!//
#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
using namespace std;
void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    int x = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        temp -= i;
        x += m[temp];
        m[temp]++;
    }
    cout << x << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}