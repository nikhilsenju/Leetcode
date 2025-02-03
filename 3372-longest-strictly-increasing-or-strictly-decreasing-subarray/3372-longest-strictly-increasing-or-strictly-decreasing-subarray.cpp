class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int> tmp,tmp1;
                for(int k=i;k<=j;k++){
                    tmp.push_back(nums[k]);
                }
                int fl = 0;
                int sz = tmp.size();
                for(int i=1;i<tmp.size();i++){
                    if(tmp[i]<=tmp[i-1]){
                        fl=1;
                        break;
                    }
                }
                if(!fl){
                    maxi=max(maxi,sz);
                }
                fl=0;
                for(int i=1;i<tmp.size();i++){
                    if(tmp[i]>=tmp[i-1]){
                        fl=1;
                        break;
                    }
                }
                if(!fl){
                    maxi=max(maxi,sz);
                }


            }
        }
        return maxi;
        
    }
};