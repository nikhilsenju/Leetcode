class Solution {
public:
    int minDays(int n) {
        unordered_map<int, int> memo;

        function<int(int)> dfs = [&](int n) -> int {
            if (n <= 1) return n;
            if (memo.count(n)) return memo[n];
            return memo[n] = 1 + min(n % 2 + dfs(n / 2), n % 3 + dfs(n / 3));
        };

        return dfs(n);
    }
};
