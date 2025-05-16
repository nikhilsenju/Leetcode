class Solution {
public:
    bool cmp(pair<string,int>&a,pair<string,int>&b){
        if(a.second==b.second){
            return false;
        }
        string x = a.first;
        string y = b.first;
        int n = x.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(a.first[i]!=b.first[i]){
                c++;
            }
        }
        return c==1;

    }
    vector<string> func(vector<pair<string,int>>&vp){
        int n = vp.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(cmp(vp[i],vp[j])&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
        }
        int ans = -1;
        int lastidx = -1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastidx=i;
            }
        }
        vector<string>tmp;
        tmp.push_back(vp[lastidx].first);
        while(hash[lastidx]!=lastidx){
            lastidx=hash[lastidx];
            tmp.push_back(vp[lastidx].first);
        }
        reverse(tmp.begin(),tmp.end());
        return tmp;

    }
    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& g) {
        int n = w.size();
        map<int,vector<pair<string,int>>> mp;
        for(int i=0;i<n;i++){
            mp[w[i].size()].push_back({w[i],g[i]});
        }
        for(auto i:mp){
            for(auto j:i.second){
                cout<<j.first<<" "<<j.second<<endl;
            }
            cout<<endl;
        }
        vector<string> ans;
        for(auto i:mp){
            vector<string> cur = func(i.second);
            if(cur.size()>ans.size()){
                ans = cur;
            }
        }
        return ans; 
    }

};