//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

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
    int n;
    map<string, int> m;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        m[s]++;
    }
    int q = 0;
    cin >> q;
    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        cout << m[s] << endl;
    }
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}