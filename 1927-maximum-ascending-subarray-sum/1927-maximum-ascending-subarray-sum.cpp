class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=nums[i];
                for(int k=i+1;k<=j;k++){
                    if(nums[k]>nums[k-1]){
                        sum+=nums[k];
                    }
                    else{
                        break;
                    }

                }
                maxi=max(maxi,sum);
            }
        }
        return maxi;
        
    }
};