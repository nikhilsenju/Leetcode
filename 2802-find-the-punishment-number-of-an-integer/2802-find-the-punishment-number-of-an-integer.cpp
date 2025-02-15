class Solution {
public:
    bool solve(int ind,string &s,int sum , int tar ,vector<vector<int>>&dp){
        if(ind==s.size()){
            return sum == tar;
        }
        if(sum>tar){return false;}
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        bool part = false;
        for(int i=ind;i<s.size();i++){
            string ns = s.substr(ind,i-ind+1);
            int add = stoi(ns);
            part = part || solve(i+1,s,sum+add,tar,dp);
            if(part==true){
                return true;
            }

        }
        return dp[ind][sum]=part;



    }
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1;i<=n;i++){
            int num = i*i;
            string s = to_string(num);
            vector<vector<int>>dp(s.size(),vector<int>(i+1,-1));
            if(solve(0,s,0,i,dp)){
                sum+=i*i;
            }
        }
        return sum;
        
    }
};