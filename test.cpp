#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    // Find all non-palindromic segments
    int non_palindrome_segments = 0;
    int non_palindrome_length = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            ++non_palindrome_segments;
            non_palindrome_length += non_palindrome_segments;
            non_palindrome_segments = 0;
        } else {
            ++non_palindrome_segments;
        }
    }
    non_palindrome_length += non_palindrome_segments;

    // Output the sum for each query
    while (q--) {
        cout << non_palindrome_length << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
