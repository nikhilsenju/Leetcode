class Solution {
public:
    vector<string> ans;
    void dfs(int idx,int cost , bool prev,int k,int n ,string &curr){
        if(cost>k){
            return;
        }
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back('0');
        dfs(idx+1,cost,false,k,n,curr);
        curr.pop_back();
        if(!prev){
            curr.push_back('1');
            dfs(idx+1,cost+idx,true,k,n,curr);
            curr.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string curr;
        dfs(0,0,false,k,n,curr);
        return ans;
        
    }
};