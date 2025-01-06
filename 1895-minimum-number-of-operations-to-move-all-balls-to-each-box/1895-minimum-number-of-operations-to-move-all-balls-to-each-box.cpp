class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        vector<pair<int,int>> pre(n+1);
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'){
                pre[i].first=1;
                pre[i].second=i;
            }
        }
        for(int i=1;i<=n;i++){
            pre[i].first+=pre[i-1].first;
            pre[i].second+=pre[i-1].second;
        }
        for(int i=1;i<=n;i++){
            int lf = pre[i].first-pre[0].first;
            int rg = pre[n].first-pre[i].first;
            int lefsum = pre[i].second-pre[0].second;
            int rghsum = pre[n].second-pre[i].second;
            ans.push_back((lf*i-lefsum)+(rghsum-rg*i));
        }
        return ans;




    }
};