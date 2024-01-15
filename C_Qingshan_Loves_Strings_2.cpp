#include <bits/stdc++.h>

#include "C:\Users\Yusuf Reza Hasnat\OneDrive\Desktop\CP\debug.h"
using namespace std;

int cap;
vector<pair<int, pair<int, int>>> v;
int cal_ub(int i) {
    return v[i].second.second + (cap - v[i].second.first) * v[i + 1].first;
}

class Node {
   public:
    int id, v, w, ub;
    Node() { v = id = w = ub = 0; }
    Node(int id, int v, int w, int ub) {
        this->id = id;
        this->v = v;
        this->w = w;
        this->ub = ub;
    }
};

int32_t main() {
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second.first >> v[i].second.second;
        v[i].first = v[i].second.second / v[i].second.first;
    }
    sort(v.rbegin(), v.rend());
    dbg(v);
    cin >> cap;
    queue<Node> q;  /// w v ub
    int ub = cal_ub(0);
    Node temp(-1, 0, 0, 100);
    int mx = -1;
    q.push(temp);
    while (q.size()) {
        Node x = q.front();
        q.pop();
        int new_w = x.w + v[x.id + 1].second.first;
        int new_v = x.v + v[x.id + 1].second.second;
        int new_ub = x.v + (cap - x.w) * v[x.id + 1].first;
        if (new_w <= cap) {
            q.push(Node(x.id + 1, new_v, new_w, new_ub));
            mx = max(mx, new_v);
        }
    }
    cout << mx << endl;
}