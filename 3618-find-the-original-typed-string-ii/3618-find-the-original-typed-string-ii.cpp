typedef long long ll;
class Solution {
public:
    ll mod = 1e9 + 7;
    int possibleStringCount(string s, int k) {
        ll n = s.size();
        vector<ll> seg;
        ll count = 0;
        ll ch = s[0];
        for (int i = 0; i < n; i++) {
            if (s[i] == ch) {
                count++;
            } else {
                seg.push_back(count);
                count = 1;
                ch = s[i];
            }
        }
        seg.push_back(count);
        ll tot = 1;
        for (auto i : seg) {
            tot = (tot * i) % mod;
            tot = tot % mod;
        }
        if (seg.size() >= k) {
            return tot;
        }
        for (auto& i : seg) {
            i--;
        }
        k -= seg.size();
        vector<ll> dp(k);
        dp[0] = 1;
        for (auto x : seg) {
            vector<ll> prev(k);
            prev[0] = dp[0];
            for (int i = 1; i < k; i++) {
                prev[i] = (prev[i - 1] + dp[i]) % mod;
                prev[i] %= mod;
            }
            for (int i = 0; i < k; i++) {
                if (i - x - 1 >= 0) {
                    dp[i] = (prev[i] - prev[i - x - 1] + mod) % mod;
                } else {
                    dp[i] = (prev[i]) % mod;
                }
                dp[i] %= mod;
            }
        }
        ll inv = 0;
        for (int i = 0; i < k; i++) {
            inv = (inv + dp[i]) % mod;
            inv %= mod;
        }
        ll ans = (tot - inv + mod) % mod;
        return ans;
    }
};