class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n+1);
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]+nums[i-1];
        }
        double maxi = -1000000000.00;
        for(int i=k;i<=n;i++){
            int sum = pref[i]-pref[i-k];
            double ans = double(sum)/double(k);
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};