class Solution {
public:
    string smallestNumber(string s) {
        int n = s.size();
        stack<int> st;
        string res;
        for(int i=0;i<=s.size();i++){
            st.push(i+1);
            if(i==n || s[i]=='I'){
                while(!st.empty()){
                    res.push_back(st.top()+'0');
                    st.pop();
                }
            }
        }
        return res;
        
    }
};