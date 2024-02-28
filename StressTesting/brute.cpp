//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 27|02|2024 21:28:02            !//
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(vf(a));

    auto isPossible = [&](){
        int md = a[0];
        for(int i = 1; i < n; i++){
            if(md % a[i] == 0){
                return false;
            }
            else
                md = md % a[i];
        }
        return true;
    };

    int f = 0;
    if(isPossible())
        f = 1;
    // cout << f << endl;
    while(next_permutation(vf(a))){
        if(isPossible()){
            f = 1;
            break;
        }
    }
    if(f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    // can you optimize this code in O(nlogn) or O(n) time complexity?
    // if you can, then you are a good programmer.
    //solution code
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    // int one = count(vf(a), 1);
    // if(one > 1){
    //     cout << "NO" << endl;
    //     return;
    // }
    // for(int i = 0; i < n; i++){
    //     if(mod % a[i] == 0){
    //         cout << "NO" << endl;
    //         return;
    //     }
    //     mod = mod % a[i];
    // }
    // cout << "YES" << endl;
}


int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}