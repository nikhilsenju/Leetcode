class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(!st.empty() && (c>='0' && c<='9')){
                st.pop();
            }
            else{
                st.push(c);
            }

        }
        string ss;
        while(!st.empty()){
            ss.push_back(st.top());
            st.pop();
        }
        reverse(ss.begin(),ss.end());
        return ss;
        
    }
};

