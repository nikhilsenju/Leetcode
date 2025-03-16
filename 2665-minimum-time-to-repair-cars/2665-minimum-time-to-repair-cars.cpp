class Solution {
public:
    long long repairCars(vector<int>& v, int c) {
        int maxr = v[0];
        int minr = v[0];
        for(auto i:v){
            maxr = max(maxr,i);
            minr = min(minr,i);
        }
        vector<int> f(maxr+1,0);
        for(auto i:v){
            f[i]++;
        }
        long long lo = 1;
        long long hi = (long long)1*minr*c*c;
        long long ans = -1;
        while(hi>=lo){
            long long mid = (hi+lo)/2;
            long long cr = 0;
            for(int i=1;i<=maxr;i++){
                cr+=f[i]*(long long)sqrt(mid/(long long)i);
            }
            if(cr>=c){
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