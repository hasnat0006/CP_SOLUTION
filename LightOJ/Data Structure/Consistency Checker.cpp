//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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

int mod = 110000007;
float pi = acos(-1);
int inf = 1e18;

class Node {
   public:
    int EoW;
    Node *child[11];
    Node() {
        EoW = 0;
        for (int i = 0; i < 11; i++)
            this->child[i] = NULL;
    }
};

void trie_insert(Node *root, string s) {
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - '0';
        if (root->child[id] == NULL)
            root->child[id] = new Node();
        root = root->child[id];
    }
    root->EoW += 1;
}
bool have_Child(Node *root) {
    for (int i = 0; i < 11; i++) {
        if (root->child[i] != NULL)
            return true;
    }
    return false;
}

int f = 1;

void check_Prefix(Node *root) {
    if (root->EoW > 0 and have_Child(root)) {
        f = 0;
        return;
    }
    for (int i = 0; i < 11; i++) {
        if (root->child[i] != NULL) {
            check_Prefix(root->child[i]);
        }
    }
}

void delete_trie(Node *root) {
    for (int i = 0; i < 11; i++) {
        if (root->child[i] != NULL) {
            delete_trie(root->child[i]);
        }
    }
    delete root;
}

void Lexicographical_sort(Node *root, string s = "") {
    if (root->EoW > 0)
        cout << s << " - " << root->EoW << endl;
    for (int i = 0; i < 11; i++) {
        if (root->child[i] != NULL) {
            char temp = i + '0';
            Lexicographical_sort(root->child[i], s + temp);
        }
    }
}

void solve() {
    f = 1;
    int n;
    string s;
    cin >> n;
    Node *trie = new Node();
    while (n--) {
        cin >> s;
        trie_insert(trie, s);
    }
    check_Prefix(trie);
    f ? cout << "YES" : cout << "NO", cout << endl;
    delete_trie(trie);
    // Lexicographical_sort(trie);
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