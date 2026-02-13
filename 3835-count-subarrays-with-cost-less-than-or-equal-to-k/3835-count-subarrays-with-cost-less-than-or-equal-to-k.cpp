#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n = nums.size();
        ll ans = 0;
        multiset<ll> mt;
        ll l = 0;
        ll r = 0;
        while(r<n && l<=r){
            mt.insert(nums[r]);
            while(!mt.empty() && (*(--mt.end())-*(mt.begin()))*(r-l+1)>k){
              mt.erase(mt.find(nums[l]));
              l++;  
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};