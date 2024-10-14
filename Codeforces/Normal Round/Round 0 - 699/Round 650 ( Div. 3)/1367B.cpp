#include <bits/stdc++.h>
using namespace std;
void find() {
    int n, even = 0, odd = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if ((arr[i] % 2 != 0 && i % 2 == 0))
            even++;
        else if ((arr[i] % 2 != 1 && i % 2 == 1))
            odd++;
    }
    // cout<<even<<" "<<odd;
    if (even != odd)
        cout << "-1" << endl;
    else
        cout << even << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        find();
    return 0;
}