class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, long long> mp;

        for (int x : nums)
            mp[x]++;

        long long ans = 1;

        // Handle the special case of 1
        long long ones = mp[1];
        if (ones % 2 == 0)
            ones--;
        ans = max(ans, ones);

        // Maximum possible depth for nums[i] <= 1e9 is about 5
        for (int i = 1; i <= 5; i++) {

            long long k = 1LL << i;

            for (auto &it : mp) {

                long long cur = it.first;

                if (cur == 1)
                    continue;

                bool ok = true;

                for (long long p = 1; p <= k; p <<= 1) {

                    auto itr = mp.find(cur);

                    if (p == k) {
                        if (itr == mp.end() || itr->second < 1) {
                            ok = false;
                            break;
                        }
                    } else {
                        if (itr == mp.end() || itr->second < 2) {
                            ok = false;
                            break;
                        }
                    }

                    if (p != k) {
                        if (cur > 1000000000LL / cur) {
                            ok = false;
                            break;
                        }
                        cur *= cur;
                    }
                }

                if (ok)
                    ans = max(ans, 2LL * i + 1);
            }
        }

        return (int)ans;
    }
};