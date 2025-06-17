class Solution {
public:
    void solve(int ind ,int tar,vector<int>&v,vector<vector<int>>&ans,vector<int>&tmp){
        if(ind==v.size()){
            if(tar==0){
                ans.push_back(tmp);
            }
            return;
        }    

        if(tar>=v[ind]){
            tmp.push_back(v[ind]);
            solve(ind,tar-v[ind],v,ans,tmp);
            tmp.pop_back();
        }
        solve(ind+1,tar,v,ans,tmp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int tar) {
        vector<vector<int>>ans;
        vector<int> tmp;
        solve(0,tar,candidates,ans,tmp);
        return ans;

    }
};