class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> tmp={1};
        ans.push_back(tmp);
        for(int i=0;i<n-1;i++){
            vector<int> curtmp;
            curtmp.push_back(1);
            for(int j=1;j<tmp.size();j++){
                curtmp.push_back(tmp[j]+tmp[j-1]);
            }
            curtmp.push_back(1);
            ans.push_back(curtmp);
            tmp=curtmp;
        }
        return ans;

    }
};