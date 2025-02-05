class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;
        int tot = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n + 1), right(n + 1);
        
        // Generate all subsets for left and right halves
        for (int i = 0; i < (1 << n); i++) {
            int suml = 0, sumr = 0, sz = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sz++;
                    suml += nums[j];
                    sumr += nums[j + n];
                }
            }
            left[sz].push_back(suml);
            right[sz].push_back(sumr);
        }


        for (int i = 0; i <= n; i++) {
            sort(left[i].begin(), left[i].end());
            sort(right[i].begin(), right[i].end());
        }

        int res = INT_MAX;
        
    
        for (int i = 0; i <= n; i++) {
            for (auto a : left[i]) {
                int b = (tot - 2 * a) / 2;
                auto& v = right[n - i];
                auto it = lower_bound(v.begin(), v.end(), b);
                
                if (it != v.end()) {
                    res = min(res, abs(tot - 2 * (a + *it)));
                }
                if (it != v.begin()) {
                    it--;
                    res = min(res, abs(tot - 2 * (a + *it)));
                }
            }
        }

        return res;
    }
};
