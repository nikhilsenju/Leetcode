class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool ans = true;
        for(int i=1;i<n;i++){
            if((nums[i]+nums[i-1])%2==0){
                return false;
            }
        }
        return true;
        
    }
};