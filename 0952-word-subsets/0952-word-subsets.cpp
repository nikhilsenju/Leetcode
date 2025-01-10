class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxi(26,0);
        for(auto i:words2){
            vector<int> tmpmx(26,0);
            for(auto j:i){
                tmpmx[j-'a']++;
            }
            for(int k=0;k<26;k++){
                maxi[k]=max(maxi[k],tmpmx[k]);
            }
        }
        vector<string> ans;
        for(auto i:words1){
            vector<int> tmp(26,0);
            for(auto j:i){
                tmp[j-'a']++;

            }
            int f = 0;
            for(int k=0;k<26;k++){
                if(tmp[k]<maxi[k]){
                    f=1;
                    break;
                }
            }
            if(!f){
                ans.push_back(i);

            }
        }
        return ans;

        
    }
};