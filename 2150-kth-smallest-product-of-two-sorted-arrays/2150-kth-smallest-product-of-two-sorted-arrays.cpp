typedef long long ll;
class Solution {
public:
    ll solve(vector<int>&v,ll x1,ll mid){
        ll lo = 0;
        ll hi = v.size()-1;
        ll ans = 0;
        while(hi>=lo){
            ll nmid = (hi+lo)/2;
            if((x1>=0 && v[nmid]*x1<=mid)|| (x1<0 && v[nmid]*x1>mid)){
                lo = nmid+1;
            }
            else{
                hi = nmid-1;
            }
        }
        if(x1>=0){
            return lo;
        }
        else{
            return v.size()-lo;
        }
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        ll n1 = nums1.size();
        ll lo = -1e10;
        ll hi = 1e10;
        ll ans = 0;
        while(hi>=lo){
            ll mid = (hi+lo)>>1;
            ll count = 0;
            for(auto i:nums1){
                count+=solve(nums2,i,mid);
            }
            if(count<k){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return lo;
        
    }
};