class Solution {
public:
    bool solve(vector<int>&v,int h,int mid){
        int tot = 0;
        for(auto i:v){
            tot+=(i+mid-1)/mid;
        }
        return tot<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = INT_MAX;
        int ans = 0;
        while(hi>=lo){
            int mid = lo+(hi-lo)/2;
            if(solve(piles,h,mid)){
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