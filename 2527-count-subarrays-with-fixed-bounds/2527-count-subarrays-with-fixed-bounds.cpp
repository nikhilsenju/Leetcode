class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        vector<int> v(n, 0);
        int prev = n;

        // Step 1: Preprocess next invalid positions
        for (int i = n - 1; i >= 0; i--) {
            if (!(nums[i] >= minK && nums[i] <= maxK)) {
                prev = i;
            }
            v[i] = prev;
        }

        int i = 0, j = 0;
        multiset<int> mt;

        // Step 2: Sliding window with multiset
        while (i < n && j < n) {
            mt.insert(nums[j]);

            if (*mt.rbegin() > maxK || *mt.begin() < minK) {
                mt.clear();  // Reset window
                i = j + 1;
                j = i;
                continue;
            }

            if (*mt.rbegin() == maxK && *mt.begin() == minK) {
                while (!mt.empty() && *mt.rbegin() == maxK && *mt.begin() == minK) {
                    ans += (v[j] - j);
                    mt.erase(mt.find(nums[i]));
                    i++;
                }
            }

            j++;
        }

        return ans;
    }
};
