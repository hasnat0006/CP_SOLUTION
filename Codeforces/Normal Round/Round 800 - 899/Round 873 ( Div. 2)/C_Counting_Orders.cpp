//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int binaryExponetiation(int base, int power, int modulo) {
    int ans = 1;
    while (power) {
        if (power % 2 == 1)
            ans = (ans * base) % modulo;
        base = (base * base) % modulo;
        power /= 2;
    }
    return ans;
}
int fact(int n) {
    int ans = 1;
    for (int i = n; i > 1; i--)
        ans *= i;
    return ans;
}
int count(vector<int> &a, vector<int> &b, int n) {
    int x = 1, y = 0;
    for (int i = 0; i < n; i++) {
        while (y < n and b[y] < a[i])
            y++;
        x = (x * (y - i)) % mod;
    }
    return x;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << count(a, b, n) << endl;
}

int32_t main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}