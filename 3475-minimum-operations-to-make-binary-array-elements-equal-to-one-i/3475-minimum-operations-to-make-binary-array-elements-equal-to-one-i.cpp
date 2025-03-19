class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=2;i<n;i++){
            if(nums[i-2]==0){
                count++;
                nums[i-2]=1;
                nums[i-1]=nums[i-1]^1;
                nums[i]=nums[i]^1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                return -1;
            }
        }
        return count;

        
    }
};