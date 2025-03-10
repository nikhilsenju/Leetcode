class Solution {
public:
    long long solve(string& s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        map<char, int> mp;
        int c = 0;
        long long ans = 0;
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        while (i < n && j < n) {
            if (st.count(s[j])) {
                mp[s[j]]++;
            } else {
                c++;
            }

            while (mp.size() == 5 && c >= k) {
                ans += (n - j);
                if (st.count(s[i])) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                } else {
                    c--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return solve(word,k)-solve(word,k+1);
    }
};