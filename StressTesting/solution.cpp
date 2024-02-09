//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA  cin.tie(NULL), 
#define HASNAT cout.tie(NULL)

int mod  = 1000000007;
int inf  = 1e18;

void solve()
{
    int n, x;
    cin >> n;
    vector<int> v(n);
    int gcd = inf;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        gcd = min(gcd, v[i]);
    }
    // dbg(gcd);
    if(gcd == 1){
        cout <<  n << endl;
        return;
    }
    sort(vf(v));
    set<int> val;
    map<int,int> actual,cnt;
    for(int i = 0; i < n; i++){
        x = v[i];
        if(actual[x] == 0){
            int id = inf;
            for(int j = 2; j * j <= x; j++){
                if(x % j == 0){
                    int div2 = x / j;
                    if(val.find(j) != val.end()){
                        actual[x] = actual[j] ? actual[j] : j;
                        id = inf;
                        break;
                    }
                    else if(val.find(div2) != val.end()){
                        id = min({id, div2});
                    }
                }
            }
            if(actual[x] == 0 and id != inf) 
                actual[x] = id;
            else if(actual[x] == 0)
                actual[x] = x;
        }
        val.insert(x);
        cnt[x]++;
    }
    
    // dbg(val);
    int ans = 0;
    for(auto i : actual){
        int mul = cnt[i.first];
        ans += (mul * i.second);
    }
    cout << ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}