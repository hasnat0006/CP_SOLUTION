//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 02|05|2024 21:30:22            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug.h"
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

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    int n, k, SA, SB;
    cin >> n >> k >> SA >> SB;
    vector<int> p(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> PlayerA, PlayerB;
    PlayerA.push_back(0);
    PlayerB.push_back(0);
    PlayerA.push_back(SA);
    PlayerB.push_back(SB);
    vector<bool> visA(200005, false), visB(200005, false);
    visA[PlayerA[1]] = true;
    visB[PlayerB[1]] = true;
    while(visA[p[SA]] == false){
        PlayerA.push_back(p[SA]);
        visA[p[SA]] = true;
        SA = p[SA];
    }
    while(visB[p[SB]] == false){
        PlayerB.push_back(p[SB]);
        visB[p[SB]] = true;
        SB = p[SB];
    }
    dbg(PlayerA);
    dbg(PlayerB);
    int ScoreA = 0, ScoreB = 0;
    vector<int> prefA(PlayerA.size() + 1), prefB(PlayerB.size() + 1);
    for(int i = 1; i < (int)PlayerA.size(); i++)
        prefA[i] = prefA[i - 1] + a[PlayerA[i]];
    dbg(prefA);
    for(int i = 1; i < (int)PlayerA.size() and i <= k; i++){
        ScoreA = max(ScoreA, (k - (i - 1)) * a[PlayerA[i]] + prefA[i - 1]);
        dbg(ScoreA);
    }
    dbg(ScoreA);
    for(int i = 1; i < (int)PlayerB.size(); i++)
        prefB[i] = prefB[i - 1] + a[PlayerB[i]];
    dbg(prefB);
    for(int i = 1; i < (int)PlayerB.size() and i <= k; i++){
        ScoreB = max(ScoreB, (k - (i - 1)) * a[PlayerB[i]] + prefB[i - 1]);
        dbg(ScoreB);
    }
    if(ScoreA == ScoreB)
        cout << "Draw" << endl;
    else if(ScoreA > ScoreB)
        cout << "Bodya" << endl;
    else
        cout << "Sasha" << endl;

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