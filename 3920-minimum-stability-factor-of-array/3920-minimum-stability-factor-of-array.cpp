#include <bits/stdc++.h>
using namespace std;

class GCDSparseTable {
    vector<vector<int>> st;
    vector<int> logg;
    int n;

public:
    GCDSparseTable(const vector<int>& a) {
        n = a.size();
        int maxLog = log2(n) + 1;
        st.assign(n, vector<int>(maxLog));
        logg.resize(n + 1);

        // Precompute logs
        logg[1] = 0;
        for (int i = 2; i <= n; i++)
            logg[i] = logg[i / 2] + 1;

        // Initialize base level (j = 0)
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];

        // Build sparse table
        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int L, int R) {
        int j = logg[R - L + 1];
        return __gcd(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

class Solution {
    GCDSparseTable* gc; // pointer to sparse table
public:
    bool solve(int mid, vector<int>& nums, int maxc) {
        int n = nums.size();
        int i = 0;
        int c = 0;
        while (i + mid - 1 < n) {
            if (gc->query(i, i + mid - 1) >= 2) {
                c++;
                i = i + mid;
            } else {
                i++;
            }
        }
        return c <= maxc;
    }
    bool check(int mid,vector<int>&nums){
        int n = nums.size();
        int i = 0;
        int c = 0;
        while (i + mid - 1 < n) {
            if (gc->query(i, i + mid - 1) >= 2) {
                return true;
            } 
            i++;
        }
        return false;
    }
    int help(vector<int>&nums){
        int n = nums.size();
        int lo = 1;
        int hi = n;
        int ans = n;
        while(hi>=lo){
            int mid = (hi+lo)>>1;
            if(check(mid,nums)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
    int minStable(vector<int>& nums, int maxC) {
        int n = nums.size();
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 1; }))
            return 0;
        GCDSparseTable table(nums);
        gc = &table;
        if(maxC==0){
            return help(nums);
        }

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (solve(mid, nums, maxC)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans-1;
    }
};