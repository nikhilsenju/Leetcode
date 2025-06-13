typedef long long ll;
class Solution {
public:
    bool solve(ll mid,vector<int>&nums,int p){
        ll c = 0;
        ll ind = 0;
        while(ind<nums.size()-1){
            if((nums[ind+1]-nums[ind])<=mid){
                c++;
                ind++;
            }
            ind++;
        }
        return c>=p;
    }
    int minimizeMax(vector<int>& nums, int p){
        ll n = nums.size();
        sort(nums.begin(),nums.end());
        ll hi = 1e9;
        ll lo = 0;
        ll ans = 0;
        while(hi>=lo){
            ll mid = (hi+lo)/2;
            if(solve(mid,nums,p)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;

            }

        }
        return ans;
    }
};