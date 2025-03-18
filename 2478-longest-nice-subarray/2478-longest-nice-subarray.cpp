class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int i = 0;
        int j = 0;
        int cur = 0;
        while(i<n && j<n){
            while((cur&nums[j])!=0){
                cur^=nums[i];
                i++;
            }
            cur|=nums[j];
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;

        
    }
};