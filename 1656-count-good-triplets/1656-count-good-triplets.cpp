class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        
        for (int j = 1; j < n; ++j) {
            // Frequency array for values arr[i], i < j
            vector<int> freq(1001, 0);

            for (int i = 0; i < j; ++i) {
                freq[arr[i]]++;
            }

            // Build prefix sum
            vector<int> prefixSum(1001, 0);
            prefixSum[0] = freq[0];
            for (int i = 1; i <= 1000; ++i) {
                prefixSum[i] = prefixSum[i - 1] + freq[i];
            }

            for (int k = j + 1; k < n; ++k) {
                if (abs(arr[j] - arr[k]) <= b) {
                    int lj = arr[j] - a, rj = arr[j] + a;
                    int lk = arr[k] - c, rk = arr[k] + c;
                    int l = max(0, max(lj, lk));
                    int r = min(1000, min(rj, rk));
                    if (l <= r) {
                        if (l == 0)
                            ans += prefixSum[r];
                        else
                            ans += prefixSum[r] - prefixSum[l - 1];
                    }
                }
            }
        }
        return ans;
    }
};
