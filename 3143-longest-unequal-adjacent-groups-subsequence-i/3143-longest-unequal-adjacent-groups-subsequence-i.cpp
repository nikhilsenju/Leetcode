class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& g) {
        int n = g.size();
        int ls = g[0];
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(g[i]!=ls){
                ans.push_back(words[i]);
                ls=g[i];
            }
        }
        
        return ans;
    }
};