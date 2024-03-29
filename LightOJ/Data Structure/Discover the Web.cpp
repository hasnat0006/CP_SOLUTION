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
    stack<string> stk, stk2;  //! back,forward
    stk.push("http://www.lightoj.com/");
    while (1) {
        string in, st;
        cin >> in;
        if (in == "VISIT") {
            // getline(cin, st);
            // st.erase(st.begin());
            cin >> st;
            stk.push(st);
            cout << st << endl;
            while (!stk2.empty())
                stk2.pop();
        }
        else if (in == "BACK") {
            if (stk.size() <= 1) {
                cout << "Ignored\n";
                // stk.push(stk2.top());
                // stk2.pop();
            }
            else {
                stk2.push(stk.top());
                stk.pop();
                cout << stk.top() << endl;
            }
        }
        else if (in == "FORWARD") {
            if (stk2.empty()) {
                cout << "Ignored\n";
            }
            else {
                cout << stk2.top() << endl;
                stk.push(stk2.top());
                stk2.pop();
            }
        }
        else if (in == "QUIT")
            break;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": \n";
        solve();
    }
    return 0;
}