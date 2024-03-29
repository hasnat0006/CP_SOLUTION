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
    int EoW;
    Node *child[6];
    Node() {
        EoW = 0;
        for (int i = 0; i < 6; i++)
            this->child[i] = NULL;
    }
};

int index(char a) {
    if (a == 'A')
        return 0;
    if (a == 'C')
        return 1;
    if (a == 'G')
        return 2;
    if (a == 'T')
        return 3;
}

void insert(Node *root, string s) {
    for (int i = 0; i < s.size(); i++) {
        int id = index(s[i]);
        if (root->child[id] == NULL)
            root->child[id] = new Node();
        root = root->child[id];
        root->EoW += 1;
        dbg(root->EoW);
    }
}

int mx = 0;
void check(Node *root, int num = 0) {
    if (root->EoW)
        mx = max(mx, (root->EoW) * num);
    dbg(mx, root->EoW);
    for (int i = 0; i < 6; i++) {
        if (root->child[i] != NULL) {
            check(root->child[i], num + 1);
        }
    }
}

void delete_trie(Node *root) {
    for (int i = 0; i < 6; i++) {
        if (root->child[i] != NULL) {
            delete_trie(root->child[i]);
        }
    }
    delete root;
}

void solve() {
    int n;
    cin >> n;
    Node *root = new Node();
    while (n--) {
        string s;
        cin >> s;
        insert(root, s);
    }
    check(root);
    cout << mx << endl;
    mx = 0;
    delete_trie(root);
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        case(i);
        solve();
    }
    return 0;
}