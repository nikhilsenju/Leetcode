class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        int n = w.size();
        vector<int> pre(n+1,0);
        set<char> st={'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            if(st.count(w[i][0]) && st.count(w[i][w[i].size()-1])){
                pre[i+1]=1;
            }
            
        }
        for(int i=1;i<=n;i++){
            pre[i]+=pre[i-1];
        }
        vector<int> ans;
        for(auto i:q){
            ans.push_back(pre[i[1]+1]-pre[i[0]]);
        }
        return ans;
    }
};