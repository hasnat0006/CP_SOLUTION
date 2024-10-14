#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string num;
        cin >> num;
        if (num[0] == '0')
            cout << "0\n";
        else {
            int x = 0, c = 0;
            int f = 1;
            for (int i = 0; i < num.length(); i++) {
                if (num[i] == '?') {
                    c++;
                }
            }
            string ans;
            if (num[0] == '?') {
                ans.push_back('9');
                c--;
                while (c--)
                    ans.push_back('0');
            }
            else {
                ans.push_back('1');
                while (c--)
                    ans.push_back('0');
            }
            cout << ans << endl;
        }
    }
}