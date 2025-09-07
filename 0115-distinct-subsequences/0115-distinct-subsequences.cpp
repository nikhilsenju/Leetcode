class Solution {
public:
    int f(auto &s,auto &t,int i,int j,auto &dp){
        int n=s.size();
        int m=t.size();
        if(j>=m)return 1;
        if(i>=n)return 0;
        int a=0,b=0,c=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            a=f(s,t,i+1,j+1,dp);
            b=f(s,t,i+1,j,dp);
        }else c=f(s,t,i+1,j,dp);
        return  dp[i][j]=a+b+c;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return f(s,t,0,0,dp);
    }
};