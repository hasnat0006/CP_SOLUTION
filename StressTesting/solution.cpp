#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "D:\Documents\debug1.cpp"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int alice = 0, bob = 0, cnt = 0, l = 0, r = n - 1;
    while (l <= r) {
        if (cnt % 2) {
            if (a[l] >= a[r]) {
                bob += a[l];
                l++;
            }
            else {
                bob += a[r];
                r--;
            }
        }
        else {
            if (a[l] >= a[r]) {
                alice += a[l];
                l++;
            }
            else {
                alice += a[r];
                r--;
            }
        }
        dbg(alice, bob);
    }

    if (alice > bob)
        cout << "Alice";
    else
        cout << "Bob";

    return 0;
}