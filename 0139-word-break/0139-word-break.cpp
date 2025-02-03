class Solution {
public:
    unordered_map<int,bool> mp;
    bool f(int ind ,string &s, unordered_set<string> &st){
        if(ind==s.size()){
            return true;
        }
        if(mp.count(ind)){
            return mp[ind];
        }
        for(int i=ind;i<s.size();i++){
            string tmp = s.substr(ind,i-ind+1);
            if(st.count(tmp)){
                if(f(i+1,s,st)){
                    return mp[ind]=true;
                }
            }
        }
        return mp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto i:wordDict){
            st.insert(i);
        }
        return f(0,s,st);
        
    }
};