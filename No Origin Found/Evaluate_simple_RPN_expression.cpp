//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 08|10|2024 00:27:01            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

void solve() {
    string s;
    while(getline(cin, s)){
        vector<string> v;
        int n = s.size();
        for(int i = 0; i < n; i++){
            string temp = "";
            while(i < n and s[i] != ' '){
                temp += s[i];
                i++;
            }
            v.push_back(temp);
        }
        stack<float> st;
        int f = 0;
        for(auto x: v){
            if(x == "+"){
                if(st.size() < 2){
                    f = 1;
                    break;
                }
                float a = st.top();
                st.pop();
                float b = st.top();
                st.pop();
                st.push(a + b);
            }
            else if(x == "-"){
                if(st.size() < 2){
                    f = 1;
                    break;
                }
                float a = st.top();
                st.pop();
                float b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if(x == "*"){
                if(st.size() < 2){
                    f = 1;
                    break;
                }
                float a = st.top();
                st.pop();
                float b = st.top();
                st.pop();
                st.push(a * b);
            }
            else if(x == "/"){
                if(st.size() < 2){
                    f = 1;
                    break;
                }
                float a = st.top();
                st.pop();
                float b = st.top();
                st.pop();
                st.push(b / a);
            }
            else{
                st.push(stof(x));
            }
        }
        if(f or st.size() != 1){
            cout << "ERROR" << endl;
        }
        else{
            cout << fixed << setprecision(4) << st.top() << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++){
        solve(); 
    }
    return 0;
}