class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int mid = 0;
        int high = n-1;
        while(high>=mid){
            if(nums[mid]==0){
                swap(nums[mid],nums[lo]);
                mid++;
                lo++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};