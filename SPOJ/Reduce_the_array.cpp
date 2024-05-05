//!................  CG o nai CP o nai :)  ................!//

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve() {
    // cout << "Solving..." << endl;
    int n, x;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq, te;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    int cost = 0;
    while (pq.size() != 1) {
        int temp = pq.top();
        pq.pop();
        temp += pq.top();
        pq.pop();
        pq.push(temp);
        cost += temp;
        // cout << cost << endl;
        // te = pq;
        // while (!te.empty())
        // {
        //     cout << te.top() << " ";
        //     te.pop();
        // }
        // cout << endl;
    }
    cout << cost << endl;
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