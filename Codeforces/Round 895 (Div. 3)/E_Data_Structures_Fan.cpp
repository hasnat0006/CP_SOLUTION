//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 22|03|2024 01:36:27            !//
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

class SEGMENT_TREE {
   public:
    vector<int> v;
    vector<int> seg;
    SEGMENT_TREE(int n) {
        v.resize(n + 5);
        seg.resize(4 * n + 5);
    }
    void build(int ti, int low, int high) {
        if (low == high) {
            seg[ti] = v[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ti, low, mid);
        build(2 * ti + 1, mid + 1, high);
        seg[ti] = (seg[2 * ti] ^ seg[2 * ti + 1]);
    }
    int find(int ti, int tl, int tr, int ql, int qr) {
        if (tl > qr || tr < ql) {
            return 0;
        }
        if (tl >= ql and tr <= qr)
            return seg[ti];
        int mid = (tl + tr) / 2;
        int l = find(2 * ti, tl, mid, ql, qr);
        int r = find(2 * ti + 1, mid + 1, tr, ql, qr);
        return (l ^ r);
    }
};


void solve() {
    int n;
    cin >> n;
    SEGMENT_TREE s(n);
    for (int i = 1; i <= n; i++) {
        cin >> s.v[i];
    }
    s.build(1, 1, n);
    string st;
    cin >> st;
    int X0 = 0, X1 = 0;
    for(int i = 0; i < n; i++){
        if(st[i] == '0')
            X0 ^= s.v[i + 1];
        else
            X1 ^= s.v[i + 1];
    }
    int q;
    cin >> q;
    while(q--){
        int type, l, r, x;
        cin >> type;
        if(type == 2){
            cin >> x;
            cout << (x == 0 ? X0 : X1) << " ";
        }
        else{
            cin >> l >> r;
            int temp = s.find(1, 1, n, l, r);
            X0 ^= temp;
            X1 ^= temp;
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