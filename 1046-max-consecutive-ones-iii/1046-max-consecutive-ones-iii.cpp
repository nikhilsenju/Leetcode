class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int countz = 0;
        while (i < n && j < n) {
            if (nums[j] == 0) {
                k--;
            }
            // while k<0 try to reduce the window
            while (i<=j && k < 0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }
            ans = max(ans, (j - i + 1));
            j++;
        }
        return ans;
    }
};