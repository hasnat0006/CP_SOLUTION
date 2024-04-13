#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int same = n / m;
        if(n % m != 0)
            same++;
        if (n - same <= k)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}