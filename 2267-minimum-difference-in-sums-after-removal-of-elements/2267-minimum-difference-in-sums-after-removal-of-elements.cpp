typedef long long ll;
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        priority_queue<ll>mini;
        priority_queue<ll,vector<ll>,greater<ll>>maxi;
        vector<ll>left(n+1,0);
        ll sum = 0;
        for(int i=0;i<n;i++){
            mini.push(nums[i]);
            sum+=nums[i];
        }
        left[0]=sum;
        for(int i=n;i<2*n;i++){
            sum+=nums[i];
            mini.push(nums[i]);
            sum-=mini.top();
            mini.pop();
            left[i-(n-1)]=sum;
        }
        ll sumr = 0;
        for(int i=2*n;i<3*n;i++){
            maxi.push(nums[i]);
            sumr+=nums[i];
        }
        ll ans = left[n]-sumr;
        for(int i=2*n-1;i>=n;i--){
            sumr+=nums[i];
            maxi.push(nums[i]);
            sumr-=maxi.top();
            maxi.pop();
            ans = min(ans,left[i-n]-sumr);
        }
        return ans;


    }
};