class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> v(26,-1);
        for(int i=0;i<n;i++){
            v[s[i]-'a']=i;
        }
        stack<char> st;
        string ans;
        for(int i=0;i<n;i++){
            st.push(s[i]);
            while(!st.empty()){
                char top = st.top();
                bool exist = false;
                for(int j=0;j<top-'a';j++){
                    if(i<v[j]){
                        exist=true;
                        break;
                    }
                }
                if(exist){
                    break;
                }
                ans.push_back(st.top());
                st.pop();
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};