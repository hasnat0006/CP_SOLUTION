//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 03|09|2024 20:37:54            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    char a[n][4];
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 4; j++){
            a[i][j] = s[j];
        }
    }

    for(int i = n - 1; i>=0; i--){
        for(int j = 3; j >= 0; j--){
            if(a[i][j] == '#'){
                cout << j + 1 << " ";
                break;
            }
        }
    }
    cout << endl;
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