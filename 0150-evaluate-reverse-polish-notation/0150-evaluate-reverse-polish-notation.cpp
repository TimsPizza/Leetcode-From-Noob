class Solution {
public:
    stack<string> st;
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }
        st.push(tokens[0]);
        int index = 1;
        while (index < tokens.size() - 1) {
            auto c = tokens[index];
            if (c != "+" && c != "-" && c != "*" && c != "/") {
                st.push(c);
            }
            else {
                auto r = st.top();
                st.pop();
                auto l = st.top();
                st.pop();
                st.push(doOperation(l, r, c.c_str()[0]));
            }
            ++index;
        }
        auto op = tokens.rbegin()->c_str();
        auto r = st.top();
        st.pop();
        auto l = st.top();
        return stoi(doOperation(l, r, op[0]));
    }

    string doOperation(string l_s, string r_s, char operand) {
        auto l = stoi(l_s);
        auto r = stoi(r_s);
        if (operand == '+') {
            return to_string(l + r);
        }
        if (operand == '-') {
            return to_string(l - r);
        }
        if (operand == '*') {
            return to_string(l * r);
        }
        if (operand == '/') {
            return to_string((int)floor(l / r));
        }
        return "";
    }
};
