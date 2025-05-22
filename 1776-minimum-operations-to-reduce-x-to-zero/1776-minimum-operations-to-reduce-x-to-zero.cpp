class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        map<int,int> mp;
        int sum = 0;
        mp[0]=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[sum]=i+1;
        }
        sum = 0;
        int ans = INT_MAX;

        for(int i=n;i>=0;i--){
            if(i==n){
                if(mp.find(x)!=mp.end()){
                    ans = min(ans,mp[x]);
                }
                continue;
            }
            sum+=nums[i];
            int rem = x-sum;
            if(mp.find(rem)!=mp.end() && i>mp[rem]){
                ans = min(ans,(n-i)+mp[rem]);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};