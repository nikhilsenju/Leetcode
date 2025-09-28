class Solution {
public:
    int solve(vector<int>&nums,int sum,int l){
        int lo = l;
        int hi = nums.size()-1;
        int ans = -1;
        while(hi>=lo){
            int mid = (hi+lo)>>1;
            if(nums[mid]<sum){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n-1;i++){
            int sum = nums[i-1]+nums[i];
            int idx = solve(nums,sum,i+1);
            if(idx==-1){
                continue;
            }
            cout<<idx<<" ";
            maxi = max(maxi,sum+nums[idx]);
        }
        return maxi;
    }

};