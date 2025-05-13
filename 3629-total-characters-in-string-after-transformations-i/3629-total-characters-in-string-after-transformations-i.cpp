class Solution {
public:
    int MOD = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int> v(26,0);
        for(auto i:s){
            v[i-'a']++;
        }
        for(int i=0;i<t;i++){
            vector<int> tmp(26,0);
            for(auto j=0;j<26;j++){
                if(j!=25){
                    tmp[j+1]=(v[j])%MOD;
                }
                else{
                    tmp[0]=(tmp[0]+v[25])%MOD;
                    tmp[1]=(tmp[1]+v[25])%MOD;
                }
            }
            v=tmp;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            ans = (ans+v[i])%MOD;
        }
        return ans;
        
    }
};