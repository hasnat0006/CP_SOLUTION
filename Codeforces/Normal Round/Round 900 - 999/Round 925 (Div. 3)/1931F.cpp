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
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

/*
    Here our main idea is to check if there is a cycle in the graph or not.
    for check the cycle we can use the topological sort.

    1.  First we need to create a graph using the input.
    2.  Then we need to create a degree array to store the degree of each node.
    3.  Then we need to traverse all the nodes and check it's degree is 0 or not.
    4.  If the degree is 0 then we can push it into the queue.
    5.  Then we need to traverse the queue and pop the top element and push it into the answer array.
    6.  Then we need to decrease the degree of the adjacent nodes of the top element.
    7.  If the degree of the adjacent nodes is 0 then we can push it into the queue.
    8.  After the queue is empty we can check if the size of the answer array is equal to the number of nodes or not.
    9.  If it is equal then we can print "YES" otherwise "NO".

    let's take an example:
    input: 
    4 4
    1 2 3 4
    2 3 1 4
    3 2 1 4
    4 2 3 1
    now for the input we can create a graph like this:
    2 -> 3 -> 4
    3 -> 1 -> 4
    2 -> 1 -> 4
    2 -> 3 -> 1
    so the indegree of the nodes are:
    1 -> 2
    2 -> 0
    3 -> 2
    4 -> 3
    then we just call topo_sort function to check if there is a cycle or not.
*/

void topo_sort(int n, vector<int> &degree, unordered_map<int,set<int>> &adj, vector<int> &ans) {
    queue<int> qu;
    // traverse all the nodes and check it's degree is 0 or not..
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            qu.push(i);
        }
    }
    while (!qu.empty()) {
        int top = qu.front();
        qu.pop();
        ans.push_back(top);
        for (auto i : adj[top]) {
            degree[i]--;
            if (degree[i] == 0) {
                qu.push(i);
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, set<int>> adj;
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < k; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        for (int j = 1; j < n - 1; j++) {
            adj[temp[j]].insert(temp[j + 1]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(auto j : adj[i]){
            degree[j]++;
        }
    }
    vector<int> ans;
    topo_sort(n, degree, adj, ans);
    ans.size() == n ? cout << "YES" << endl : cout << "NO" << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}