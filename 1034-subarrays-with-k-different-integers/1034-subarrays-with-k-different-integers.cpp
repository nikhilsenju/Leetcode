class Solution {
public:
    int solve(vector<int>&v,int k){
        int n = v.size();
        int ans = 0;
        int i =0;
        int j=0;
        map<int,int> mp;
        while(i<n && j<n){
            mp[v[j]]++;
            while(mp.size()>k){
                mp[v[i]]--;
                if(mp[v[i]]==0){
                    mp.erase(v[i]);
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};