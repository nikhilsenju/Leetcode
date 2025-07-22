class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxi = 0;
        int sum = 0;
        map<int,int>mp;
        while(i<n && j<n){
            sum+=nums[j];
            mp[nums[j]]++;
            while(i<n&&mp[nums[j]]>1){
                sum-=nums[i];
                mp[nums[i]]--;
                i++;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
            }
            maxi = max(maxi,sum);
            j++;

        }
        return maxi;
    }
};