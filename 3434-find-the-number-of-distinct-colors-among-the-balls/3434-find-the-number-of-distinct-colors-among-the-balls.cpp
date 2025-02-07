class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> mpc;
        map<int,int> mp;
        vector<int> ans;
        for(auto i:queries){
            int b = i[0];
            int c = i[1];
            if(mp.find(b)!=mp.end()){
                int oldc = mp[b];
                if(mpc[oldc]==1){
                    mpc.erase(oldc);
                }
                else{
                    mpc[oldc]--;
                }
            }
            mp[b]=c;
            mpc[c]++;
            ans.push_back(mpc.size());

        }
        return ans;
        
    }
};