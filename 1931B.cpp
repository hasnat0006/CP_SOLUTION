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
    cin >> n;
    int sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i], sum += v[i];
    int each = sum / n;
    int hand = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > each)
            hand += v[i] - each;
        else if(v[i] < each){
            int drkr = each - v[i];
            if(hand >= drkr)
                hand -= drkr;
            else{
                cout << "NO" << endl;
                return;
            }
        }
    }    
    cout << "YES" << endl;
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