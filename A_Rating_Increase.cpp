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
#define pb    push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA  cin.tie(NULL), 
#define HASNAT cout.tie(NULL)

int mod  = 1000000007;
float pi = acos(-1);
int inf  = 1e18;

void solve()
{
    string s;
    cin >> s;
    int id = 0;
    if(s[1] != '0'){
        if(s[0] >= s[1] and s.size() == 2){
            cout << -1 << endl;
            return;
        }
        cout << s[0] << " ";
        for(int i = 1; i < s.size(); i++)
            cout << s[i];
        cout << endl;
        return;
    }
    string aa, bb;
    aa.push_back(s[0]);
    for(int i = 1; i < s.size();i++){
        if(s[i] != '0'){
            id = i;
            break;
        }
        aa.push_back(s[i]);
    }
    dbg(s, id);
    for(int i = id; i < s.size(); i++)
        bb.push_back(s[i]);	
    dbg(aa, bb);
    int a = stoi(aa);
    int b = stoi(bb);
    if(a >= b)
        cout << -1 << endl;
    else 
        cout << aa << " " << bb << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        // case(i)
        solve(); 
    }
    return 0;
}