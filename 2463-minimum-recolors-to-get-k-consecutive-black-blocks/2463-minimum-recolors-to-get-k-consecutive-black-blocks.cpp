class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int c = 0;
                if ((j - i + 1) >= k) {
                    for (int l = i; l <= j; l++) {
                        if (s[l] == 'W') {
                            c++;
                        }
                    }
                    ans = min(ans,c);
                }
                
            }
        }
        return ans;
    }
};