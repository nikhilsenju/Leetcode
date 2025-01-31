class Solution {
public:
    int f(int ind ,int k, vector<int>&tmp,vector<int>&nums){
        if(ind==nums.size()){
            for(int i=0;i<tmp.size();i++){
                for(int j=0;j<tmp.size();j++){
                    if(j!=i){
                        if(abs(tmp[i]-tmp[j])==k){
                            return 0;
                        }
                    }
                }
            }
            return 1;
        }
        tmp.push_back(nums[ind]);
        int l = f(ind+1,k,tmp,nums);
        tmp.pop_back();
        int r = f(ind+1,k,tmp,nums);
        return l+r;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> tmp;
        int ans = f(0,k,tmp,nums);
        return ans-1;

        
    }
};