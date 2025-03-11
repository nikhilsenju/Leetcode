class Solution {
public:
    bool isValid(map<char,int>&ms,map<char,int>&mt){
        for(auto i:mt){
            if(ms[i.first]<i.second){
                return false;
            }
        }
        return true;    
    }
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        int n=s.size();
        int i=0;
        int j=0;
        int st=0;
        int len = INT_MAX;
        map<char,int> ms;
        map<char,int> mt;
        for(auto i:t){
            mt[i]++;
        }

        while(i<n && j<n){
            ms[s[j]]++;
            while(isValid(ms,mt)){
                if(len>(j-i+1))
                {
                    len =(j-i+1);
                    st=i;
                }
                ms[s[i]]--;
                i++;
            }
            j++;
        }
        if(len==INT_MAX){
            return "";
        }
        string ans = s.substr(st,len);
        return ans;
        
    }
};