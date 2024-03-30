//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define dosomic(x) fixed << setprecision(x)
#define endl "\n"
#define case(x) cout << "Case " << x << ": "
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = acos(-1);
int inf = 1e18;

class Node {
   public:
    int div, needed, index;
    Node(int div, int needed, int index) {
        this->div = div;
        this->needed = needed;
        this->index = index;
    }
};

class comp {
   public:
    bool operator()(const Node &a, const Node &b) {
        if (a.div > b.div)
            return true;
        if (a.div == b.div) {
            if (a.needed > b.needed)
                return true;
        }
        return false;
    }
};

void solve() {
    int n, magic;
    cin >> n >> magic;
    vector<int> stone(n), coin(n);
    for (auto &i : stone)
        cin >> i;
    for (auto &i : coin)
        cin >> i;
    priority_queue<Node, vector<Node>, comp> pq;
    for (int i = 0; i < n; i++) {
        int div = coin[i] / stone[i];
        int needed = stone[i] - (coin[i] % stone[i]);
        pq.push(Node(div, needed, i));
    }
    while (magic) {
        auto top = pq.top();
        pq.pop();
        int div = top.div;
        int needed = top.needed;
        int index = top.index;
        if (needed > magic) {
            pq.push(top);
            break;
        }
        else {
            magic -= needed;
            needed = stone[index];
            div++;
            pq.push(Node(div, needed, index));
        }
    }
    cout << pq.top().div << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // case(i)
        solve();
    }
    return 0;
}