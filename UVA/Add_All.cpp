//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve() {
    while (1) {
        int n, x;
        cin >> n;
        if (n == 0)
            break;
        else {
            priority_queue<int, vector<int>, greater<int>> pq;
            while (n--) {
                cin >> x;
                pq.push(x);
            }
            int sum1 = 0;
            int sum2 = 0;
            int sum = 0;
            while (pq.size() > 1) {
                sum1 = pq.top();
                pq.pop();
                sum2 = pq.top();
                pq.pop();
                sum += (sum1 + sum2);
                pq.push((sum1 + sum2));
            }
            cout << sum << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}