class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref;
        vector<int> suff;
        int mini = nums[0];
        pref.push_back(mini);
        for(int i=1;i<n;i++){
            mini=min(mini,nums[i]);
            pref.push_back(mini);
        }
        int maxi = nums.back();
        suff.push_back(maxi);
        for(int i=n-2;i>=0;i--){
            maxi = max(maxi,nums[i]);
            suff.push_back(maxi);
        }
        reverse(suff.begin(),suff.end());
        for(int i=1;i<n-1;i++){
            if(pref[i-1]<nums[i] && nums[i]<suff[i+1]){
                return true;
            }
        }
        return false;
    }
};