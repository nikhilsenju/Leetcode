class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxii = 0;
        int mini = 0;
        int sum = 0;
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=0){
                maxii = max(maxii,abs(sum - mini));
            }
            else{
                maxii = max(maxii,abs(sum-maxi));

            }
            maxi= max(maxi,sum);
            mini=min(mini,sum);
        }
        return maxii;
        
    }
};