class Solution {
public:
    bool solve(string&a ,string&b){
        if(b.size()-a.size()==1){
            int i =0;
            int j =0;
            while(i<a.size() && j<b.size()){
                if(a[i]==b[j]){
                    i++;
                    j++;
                }
                else{
                    j++;
                }
            }
            if(i==a.size()){
                return true;
            }
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](string&a , string&b){
            return a.size()<b.size();
        });
        for(auto i:words){
            cout<<i<<" ";
        }
        cout<<endl;
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(solve(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        return maxi;
    }
};