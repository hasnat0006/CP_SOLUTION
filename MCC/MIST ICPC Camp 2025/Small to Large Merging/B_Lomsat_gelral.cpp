#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    map<int, int> freq;
    int fmx = 0, dom_sum = 0;
    Node() {}
};

const int N = 2e5;
vector<int> clr(N), ans(N);
vector<int> adj[N];
vector<Node> arr(N);

void dfs(int u, int p) {
    for (auto c : adj[u]) {
        if (c == p)
            continue;
        dfs(c, u);
        if (arr[c].freq.size() > arr[u].freq.size()) {
            swap(arr[c], arr[u]);
        }
        for (auto [x, f] : arr[c].freq) {
            arr[u].freq[x] += f;
            if (arr[u].freq[x] > arr[u].fmx) {
                arr[u].fmx = arr[u].freq[x];
                arr[u].dom_sum = x;
            }
            else if (arr[u].freq[x] == arr[u].fmx) {
                arr[u].dom_sum += x;
            }
        }
    }
    arr[u].freq[clr[u]]++;
    if (arr[u].freq[clr[u]] > arr[u].fmx) {
        arr[u].fmx = arr[u].freq[clr[u]];
        arr[u].dom_sum = clr[u];
    }
    else if (arr[u].freq[clr[u]] == arr[u].fmx) {
        arr[u].dom_sum += clr[u];
    }
    ans[u] = arr[u].dom_sum;
}

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> clr[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}
