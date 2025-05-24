class Solution {
public:
    bool ispresent(string word,char x){
        for(auto j:word){
            if(j==x){
                return true;
            }
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ispresent(words[i],x)){
                ans.push_back(i);
            }
        }
    return ans;
    }
};