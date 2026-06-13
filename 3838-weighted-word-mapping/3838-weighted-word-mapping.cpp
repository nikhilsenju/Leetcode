class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto i:words){
            int sum = 0;
            for(auto j:i){
                sum+=weights[j-'a'];
            }
            int mod = sum%26;
            char ch = 'a'+(25-mod);
            ans.push_back(ch);
        }
        return ans;
    }
};