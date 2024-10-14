#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

float apply_operator(char op, double a, double b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
    }
}

float evaluate_postfix(const string& postfix) {
    stack<float> st;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            st.push(stod(token));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/" ||
                 token == "^") {
            // if (st.size() < 2)
            //     cout << "Invalid expression" << endl;
            float b = st.top();
            st.pop();
            float a = st.top();
            st.pop();
            float result = apply_operator(token[0], a, b);
            st.push(result);
        }
    }

    // if (st.size() != 1)
    //     cout << "Invalid expression" << endl;
    return st.top();
}

int main() {
    string postfix = "3 4 + 2 * 7 /"; 
    float result = evaluate_postfix(postfix);
    cout << "Result: " << result << endl; 
    return 0;
}
