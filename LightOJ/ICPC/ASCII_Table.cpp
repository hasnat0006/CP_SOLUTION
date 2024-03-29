#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    char a, b;
    cin >> a >> b;
    int x = abs(a - b);
    set<int>v;
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            v.insert(i);
            v.insert(x/i);
        }
    }
    for(auto i : v){
        int temp = 94 / i;
        if(94 % i){
            temp++;
        }
        cout << i << " " << temp << endl;
    }
}

int32_t main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": \n";
        solve();
        cout << endl;
    }
    return 0;
}