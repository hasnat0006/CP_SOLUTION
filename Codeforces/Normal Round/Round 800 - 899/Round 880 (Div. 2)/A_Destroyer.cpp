#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mo;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mo[x]++;
        }
        int ami = -1, f = 1, paisi = INT_MAX;
        for (auto it : mo) {
            if (it.first != ami + 1 or it.second > paisi) {
                f = 0;
                break;
            }
            else {
                paisi = it.second;
                ami = it.first;
            }
        }
        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}