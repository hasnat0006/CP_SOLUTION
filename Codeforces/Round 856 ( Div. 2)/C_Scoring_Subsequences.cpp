//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 13|03|2024 15:57:53            !//
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
    int n;
    cin >> n;
    vector<int> v(n), ans(n);
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){
        int low = 1, high = i + 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(v[i - mid + 1] >= mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        ans[i] = high;
    }
    for(auto i : ans)
        cout << i << " ";
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