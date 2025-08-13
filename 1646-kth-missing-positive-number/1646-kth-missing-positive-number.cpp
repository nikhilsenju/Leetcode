class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if (k < arr[0]) return k; // handle missing before first element
        
        int lo = 0, hi = n - 1, ans = 0;
        while (hi >= lo) {
            int mid = (hi + lo) >> 1;
            int left = arr[mid] - (mid + 1); // missing count till arr[mid]
            if (k >left) {
                lo = mid + 1;
            } else {
                ans = mid;
                hi = mid - 1;
            }
        }
        return hi+k+1;
    }
};
