import java.util.*;

class Solution {

    static ArrayList<Integer>[] adj1;
    static ArrayList<Integer>[] adj2;
    static int[][][] dp;
    static int MOD = 1000000007;
    int dfs(int ind, int p1, int p2, char[] arr) {

        if (ind == arr.length) {
            return (p1 == -1 || p2 == -1) ? 0 : 1;
        }

        if (dp[ind][p1 + 1][p2 + 1] != -1) {
            return dp[ind][p1 + 1][p2 + 1];
        }

        int ch = arr[ind] - 'a';
        int ans = 0;

        // Take current character from word1
        for (int id1 : adj1[ch]) {
            if (id1 > p1) {
                ans =  (ans+dfs(ind + 1, id1, p2, arr))%MOD;
                ans = ans%MOD;
            }
        }

        // Take current character from word2
        for (int id2 : adj2[ch]) {
            if (id2 > p2) {
                ans =(ans+dfs(ind + 1, p1, id2, arr))%MOD;
                ans = ans%MOD;
            }
        }

        return dp[ind][p1 + 1][p2 + 1] = ans%MOD;
    }

    public int interleaveCharacters(String word1, String word2, String target) {

        int n = target.length();
        int n1 = word1.length();
        int n2 = word2.length();

        adj1 = new ArrayList[26];
        adj2 = new ArrayList[26];

        for (int i = 0; i < 26; i++) {
            adj1[i] = new ArrayList<>();
            adj2[i] = new ArrayList<>();
        }

        char[] s1 = word1.toCharArray();
        char[] s2 = word2.toCharArray();
        char[] arr = target.toCharArray();

        for (int i = 0; i < n1; i++) {
            adj1[s1[i] - 'a'].add(i);
        }

        for (int i = 0; i < n2; i++) {
            adj2[s2[i] - 'a'].add(i);
        }

        dp = new int[n + 1][n1 + 1][n2 + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n1; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return dfs(0, -1, -1, arr);
    }
}