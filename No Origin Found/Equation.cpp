#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool delim(char c) { return c == ' '; }

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool is_unary(char c) { return c == '+' || c == '-'; }

int priority(char op) {
    if (op < 0)  // unary operator
        return 3;
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 4;  // Power operator has higher precedence
    return -1;
}

// Instead of processing the operation, we output it in RPN format
void process_op(string& output, char op) {
    if (op < 0) {
        switch (-op) {
            case '+':
                output += "+ ";
                break;
            case '-':
                output += "- ";
                break;
        }
    }
    else {
        switch (op) {
            case '+':
                output += "+ ";
                break;
            case '-':
                output += "- ";
                break;
            case '*':
                output += "* ";
                break;
            case '/':
                output += "/ ";
                break;
            case '^':
                output += "^ ";
                break;
        }
    }
}

// Function to generate Reverse Polish Notation (RPN)
string to_rpn(string& s) {
    string output;             // This will hold the result in RPN
    stack<char> op;            // Operator stack
    bool may_be_unary = true;  // Track if the operator can be unary
    for (int i = 0; i < (int)s.size(); i++) {
        if (delim(s[i]))
            continue;

        if (s[i] == '(') {
            op.push('(');
            may_be_unary = true;
        }
        else if (s[i] == ')') {
            while (op.top() != '(') {
                process_op(output, op.top());
                op.pop();
            }
            op.pop();
            may_be_unary = false;
        }
        else if (is_op(s[i])) {
            char cur_op = s[i];
            if (may_be_unary && is_unary(cur_op))
                cur_op = -cur_op;
            while (!op.empty() &&
                   ((cur_op >= 0 && priority(op.top()) >= priority(cur_op)) ||
                    (cur_op < 0 && priority(op.top()) > priority(cur_op)))) {
                process_op(output, op.top());
                op.pop();
            }
            op.push(cur_op);
            may_be_unary = true;
        }
        else {
            char number;
            while (i < (int)s.size() && isalnum(s[i]))
                number = s[i++];
            --i;
            // cout << "Number: " << number << endl;
            output.push_back(number);
            output.push_back(' ');
            may_be_unary = false;
        }
    }

    while (!op.empty()) {
        process_op(output, op.top());
        op.pop();
    }

    return output;
}

int main() {
    int t;
    cin >> t;
    string c;
    string s;
    getline(cin, c);
    cin.ignore();
    // cout << "t: " << t << endl;/
    while (t--) {
        while (getline(cin, c)) {
            s += c;
            // cout << s << endl;
            if (c == "") {
                // cout << "hoise" << endl;
                if (s.size() > 0) {
                    // cout << s << endl;
                    string rpn = to_rpn(s);
                    for (auto x : rpn) {
                        if (x == ' ')
                            continue;
                        cout << x;
                    }
                    cout << endl << endl;
                    s.clear();
                    continue;
                }
            }
        }
        // cout << "t: " << t << endl;
    }
    if (s.size() > 0) {
        string rpn = to_rpn(s);
        for (auto x : rpn) {
            if (x == ' ')
                continue;
            cout << x;
        }
        cout << endl;
    }
    return 0;
}
