//!-----------------------------------------------------!//
//!              Author: YUSUF REZA HASNAT              !//
//!             Created: 07|10|2024 23:50:08            !//
//!-----------------------------------------------------!//

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"

const int mod = 1e9 + 7;
const int inf = 1e18;

bool delim(char c) { return c == ' '; }

bool is_op(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

bool is_unary(char c) { return c == '+' || c == '-'; }

int priority(char op) {
    if (op < 0)  // unary operator
        return 3;
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return -1;
}

void process_op(stack<int>& st, char op) {
    if (op < 0) {
        int l = st.top();
        st.pop();
        switch (-op) {
            case '+':
                st.push(l);
                break;
            case '-':
                st.push(-l);
                break;
        }
    }
    else {
        int r = st.top();
        st.pop();
        int l = st.top();
        st.pop();
        switch (op) {
            case '+':
                st.push(l + r);
                break;
            case '-':
                st.push(l - r);
                break;
            case '*':
                st.push(l * r);
                break;
            case '/':
                st.push(l / r);
                break;
        }
    }
}

int evaluate(string& s) {
    stack<int> st;
    stack<char> op;
    bool may_be_unary = true;
    for (int i = 0; i < (int)s.size(); i++) {
        cerr << "i: " << i << endl;
        if (delim(s[i])) {
            cerr << "i4: " << i << endl;
            continue;
        }
        if (s[i] == '(') {
            op.push('(');
            may_be_unary = true;
            cerr << "i1: " << i << endl;
        }
        else if (s[i] == ')') {
            while (op.top() != '(') {
                process_op(st, op.top());
                op.pop();
            }
            op.pop();
            cerr << "i2: " << i << endl;
            may_be_unary = false;
        }
        else if (is_op(s[i])) {
            cerr << "i3: " << i << endl;
            char cur_op = s[i];
            if (may_be_unary && is_unary(cur_op))
                cur_op = -cur_op;
            while (!op.empty() &&
                   ((cur_op >= 0 && priority(op.top()) >= priority(cur_op)) ||
                    (cur_op < 0 && priority(op.top()) > priority(cur_op)))) {
                process_op(st, op.top());
                op.pop();
            }
            op.push(cur_op);
            may_be_unary = true;
        }
        else {
            cout << "Number: " << s[i] << endl;
            cout << s << endl;
            cerr << "i: " << i << endl;
            int number = 0;
            string temp = "";
            while (i < (int)s.size() && s[i] != ' ') {
                // number = number * 10 + s[i++] - '0';
                temp += s[i++];
            }
            --i;
            cerr << "i: " << i << endl;
            cerr << "Number: " << temp << endl;
            st.push(number);
            may_be_unary = false;
        }
    }
    // while (!op.empty()) {
    //     process_op(st, op.top());
    //     op.pop();
    // }
    // return st.top();
    return 0;
}

void solve() {
    string s;
    while (getline(cin, s)) {
        s.push_back(' ');
        vector<string> v;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            string temp = "";
            while (i < n and s[i] != ' ') {
                temp += s[i];
                i++;
            }
            v.push_back(temp);
        }
        // for (auto x : v) {
        //     cout << x << endl;
        // }
        float a = stof(v[0]);
        float b = stof(v[2]);
        float c = stof(v[4]);
        // cout << a << " " << b << " " << c << endl;
        if(v[1] == "+" and v[3] == "+"){
            cout << a + b + c << endl;
        }
        else if(v[1] == "+" and v[3] == "-"){
            cout << a + b - c << endl;
        }
        else if(v[1] == "+" and v[3] == "*"){
            cout << a + b * c << endl;
        }
        else if(v[1] == "+" and v[3] == "/"){
            cout << a + b / c << endl;
        }
        else if(v[1] == "-" and v[3] == "+"){
            cout << a - b + c << endl;
        }
        else if(v[1] == "-" and v[3] == "-"){
            cout << a - b - c << endl;
        }
        else if(v[1] == "-" and v[3] == "*"){
            cout << a - b * c << endl;
        }
        else if(v[1] == "-" and v[3] == "/"){
            cout << a - b / c << endl;
        }
        else if(v[1] == "*" and v[3] == "+"){
            cout << a * b + c << endl;
        }
        else if(v[1] == "*" and v[3] == "-"){
            cout << a * b - c << endl;
        }
        else if(v[1] == "*" and v[3] == "*"){
            cout << a * b * c << endl;
        }
        else if(v[1] == "*" and v[3] == "/"){
            cout << a * b / c << endl;
        }
        else if(v[1] == "/" and v[3] == "+"){
            cout << a / b + c << endl;
        }
        else if(v[1] == "/" and v[3] == "-"){
            cout << a / b - c << endl;
        }
        else if(v[1] == "/" and v[3] == "*"){
            cout << a / b * c << endl;
        }
        else if(v[1] == "/" and v[3] == "/"){
            cout << a / b / c << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}