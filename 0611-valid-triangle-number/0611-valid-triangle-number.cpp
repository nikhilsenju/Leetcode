class Solution {
public:
    int solve(vector<int>& v, int tar, int i) {
        int hi = v.size() - 1;
        int lo = i + 1;
        int ans = i;
        while (hi >= lo) {
            int mid = (hi + lo) / 2;
            if (v[mid] < tar) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
            
        }
      
        return ans > i ? (ans - i) : 0;
    }

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
      
        int n = nums.size();
        int validtriangle = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i+1; j < n-1 ; j++) {
                int tar = nums[i] + nums[j];
                validtriangle += solve(nums, tar, j);
            }
        }
        return validtriangle;
    }
};