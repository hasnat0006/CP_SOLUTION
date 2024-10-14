#include <bits/stdc++.h>
#define endl "\n"
#define int long long

using namespace std;

bool primecheck(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << n - i << " " << i << endl;
            return false;
        }
    }
    return true;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a < 4 and b < 4)
            cout << "-1\n";
        else if (a == b) {
            if (primecheck(a))
                cout << "-1\n";
        }
        else {
            if (b % 2 == 0) {
                cout << b - 2 << " "
                     << "2" << endl;
            }
            else {
                cout << b - 3 << " "
                     << "2" << endl;
            }
        }
    }
}