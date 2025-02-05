#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;  // Fix MOD definition

class Solution {
public:
    ll binpow(ll a, ll b) {
        ll res = 1;
        a %= MOD;  // Ensure a is within MOD
        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        ll n = nums.size();
        ll ans = 0;
        sort(nums.begin(), nums.end());
        for (ll i = 0; i < n; i++) {
            ll idx = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            if (idx > i) {  // Fix the condition
                ans = (ans + binpow(2, idx - i - 1)) % MOD;
            }
        }
        return ans;
    }
};
