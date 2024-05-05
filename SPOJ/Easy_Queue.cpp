

#include <bits/stdc++.h>
#define int long long
#define float long double
#define pb push_back
#define endl "\n"
int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;

using namespace std;

void solve() {
    int n;
    cin >> n;
    queue<int> q;
    while (n--) {
        int ch;
        cin >> ch;
        if (ch == 1) {
            int in;
            cin >> in;
            q.push(in);
        }
        else if (ch == 2) {
            if (!q.empty())
                q.pop();
        }
        else {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << "Empty!\n";
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