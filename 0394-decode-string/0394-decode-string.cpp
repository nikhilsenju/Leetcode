class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                string cur;
                while (!st.empty() && st.top() != '[') {
                    cur.push_back(st.top());
                    st.pop();
                }
                reverse(cur.begin(), cur.end());
                st.pop();
                string num;
                while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(), num.end());
                string tmp = "";
                cout << tmp << " " << num << endl;
                for (int j = 0; j < stoi(num); j++) {
                    tmp += cur;
                }
                for (auto j : tmp) {
                    st.push(j);
                }
            }
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};