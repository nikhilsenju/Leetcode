class Solution {
public:
    long long solve(vector<int>&v,int m ,int k ,int mid){
        int tot = 0;
        int c = 0;
        for(auto i:v){
            if(i<=mid){
                c++;
            }
            else{
                c=0;
            }
            if(c>=k){
                tot++;
                c=0;
            }


        }
        return tot>=m;
    }
    int minDays(vector<int>& v, int m, int k) {
        long long n = v.size();
        long long t = 1;
        if(n<m*t*k){
            return -1;
        }
        long long lo = 0;
        long long hi = INT_MAX;
        long long ans = 0;
        while(hi>=lo){
            long long mid = lo +(hi-lo)/2;
            if(solve(v,m,k,mid)){
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