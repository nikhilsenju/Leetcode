class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans  = 0;
        map<int,int> mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int prod = nums[i]*nums[j];
                ans += mp[prod]*8;
                mp[prod]++;
            }
        }
    return ans;
    }
};