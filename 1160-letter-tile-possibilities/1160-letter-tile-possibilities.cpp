class Solution {
public:
    void f(string &curr , string &s,set<string>&st,vector<bool>&v){
        st.insert(curr);
       
        if(curr.size()>=s.size()){
            return;
        }
        for(int i=0;i<s.size();i++){
            if(v[i]){
                curr.push_back(s[i]);
                v[i]=false;
                f(curr,s,st,v);
                curr.pop_back();
                v[i]=true;
            }
        }

    }
    int numTilePossibilities(string s) {
        int n = s.size();
        set<string> st;
        string curr;
        vector<bool>vp(n,true);
        f(curr,s,st,vp);
        return st.size()-1;

        
    }
};