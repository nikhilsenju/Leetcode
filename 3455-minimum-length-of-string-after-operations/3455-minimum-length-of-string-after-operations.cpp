class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int> v(26,0);
        for(auto i:s){
            v[i-'a']++;
        }
        int len  = 0;
        for(int i=0;i<26;i++){
            if(v[i]>=3){
                if(v[i]&1){
                    len+=1;
                }
                else{
                    len+=2;
                }

            }
            else{
                len+=v[i];

            }
        }
        return len;
    }
};