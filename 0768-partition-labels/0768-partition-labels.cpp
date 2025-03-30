class Solution {
public:
    bool solve(string&str,map<char,int>&mp){
        set<char> st;
        for(auto i:str){
            st.insert(i);
        }
        for(auto i:st){
            if(mp[i]>0){
                return false;
            }
        }
        return true;

    }
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        vector<int> ans;
        string str;
        for(int i=0;i<s.size();i++){
            str.push_back(s[i]);
            mp[s[i]]--;
            if(solve(str,mp)){
                ans.push_back(str.size());
                str="";
            }
            
        }
        return ans;
        
    }
};