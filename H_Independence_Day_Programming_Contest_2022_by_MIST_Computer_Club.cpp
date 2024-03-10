//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|03|2024 23:27:27            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void print(stack<int> q){
    cout << "--> " ;
    while(q.size()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

void solve() {
    int n, x, y;
    cin >> n;
    stack<int> q;
    map<int, int> mp;
    while (n--) {
        cin >> x;
        if(x == 0){
            cin >> y;
            q.push(y);
            mp[y]++;
        }
        else if(x == 1){
            if(q.size()){
                cout << q.top() << endl;
                mp[q.top()]--;
                if(mp[q.top()] == 0)
                    mp.erase(q.top());
                q.pop();
            }
            else
                cout << "0" << endl;
        }
        else{
            if(mp.size())
                cout << mp.rbegin()->first << endl;
            else
                cout << "0" << endl;
        }
        // print(q);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}