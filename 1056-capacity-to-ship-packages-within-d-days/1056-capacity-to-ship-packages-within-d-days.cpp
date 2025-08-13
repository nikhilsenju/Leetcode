class Solution {
public:
    int solve(vector<int>&w,int d ,int mid){ 
        int days = 1;
        int count = 0;
        for(auto i:w){
            if(count+i>mid){
                days++;
                count = i;
            }
            else{
                count+=i;
            }
        }
        return days<=d;

    }
    int shipWithinDays(vector<int>& w, int d) {
        int hi = 0;
        int lo = 0;
        for(auto i:w){
            hi += i;
            lo = max(lo,i);
        }
        int ans = 0;
        while(hi>=lo){
            int mid = (hi+lo)>>1;
            if(solve(w,d,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};