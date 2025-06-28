class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.rbegin(),vp.rend());
        vector<pair<int,int>> v;
        for(int i=0;i<k;i++){
            v.push_back({vp[i].second,vp[i].first});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto i:v){
            ans.push_back(i.second);
        }
        return ans;
    }
};