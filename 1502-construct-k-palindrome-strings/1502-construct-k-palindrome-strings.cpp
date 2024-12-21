class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> v(26,0);
        for(auto i:s)
        {v[i-'a']++;}
        int c=0;
        for(auto i:v){
            if(i&1){c++;}
        }
        if(s.size()<k){return false;}
        return c<=k;

        
    }
};