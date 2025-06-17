class Solution {
public:
    void solve(int ind ,int tar,  vector<int>&v,vector<int>&tmp,vector<vector<int>>&ans){
       
            if(tar==0){
                ans.push_back(tmp);
                return;
            }

        
        for(int i=ind;i<v.size();i++){
            if(i>ind && v[i-1]==v[i]){
                continue;
            } 
            if(tar<v[i]){
                break;
            }
            tmp.push_back(v[i]);
            solve(i+1,tar-v[i],v,tmp,ans);
            tmp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0,t,c,tmp,ans);
        return ans;
    }
};