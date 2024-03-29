//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 29|03|2024 23:05:26            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

int mod = 1000000007;
int inf = 1e18;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < c; i++)
        pq.push(0);
    for(int i = 0; i < b; i++) {
        if(pq.empty()){
            cout << -1 << endl;
            return;
        }
        int x = pq.top();
        pq.pop();
        pq.push(x + 1);
    }
    for(int i = 0; i < a; i++) {
        if(pq.size() < 2){
            cout << -1 << endl;
            return;
        }
        pq.pop();
        int x = pq.top();
        pq.pop();
        pq.push(x + 1);
    }
    pq.size() == 1 ? cout << pq.top() << endl : cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}