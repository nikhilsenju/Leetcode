class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int o = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                o++;
            }

        }
        int z =0;
        int maxi=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                z++;
            }else{
                o--;
            }
            maxi=max(maxi,o+z);
        }
        return maxi;


    }
};