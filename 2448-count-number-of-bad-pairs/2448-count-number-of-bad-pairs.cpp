class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        map<int,int> mp;
        mp[0-nums[0]]++;
        for(int i=1;i<n;i++){
            ans +=(i-mp[i-nums[i]]);
            mp[i-nums[i]]++;
        }
        return ans;
        
    }
};