#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
void solve() {
    int n, c = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 1) {
            int temp = v[i];
            v.erase(v.begin() + i);
            v.push_back(temp);
            n--;
            i--;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            int x = __gcd(v[i], (2 * v[j]));
            // cout << "i: " << v[i] << "j: " << (v[j]) << " "<< "GCD: " << x <<
            // endl;
            if (x > 1)
                c++;
        }
    }
    cout << c << endl;
}
int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}