class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(int i =0;i<n;i++){
            if(nums[i]>=0){
                v[i]=nums[(i+nums[i])%n];
            }
            else{
                v[i]=nums[((i-abs(nums[i])%n)+n)%n];
            }
        }
        return v;
        
    }
};