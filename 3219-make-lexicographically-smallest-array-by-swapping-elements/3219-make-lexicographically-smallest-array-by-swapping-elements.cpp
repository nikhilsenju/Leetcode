class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end());
        vector<int> idx;
        for(auto i:vp){
            idx.push_back(i.second);
        }
        int c=1;
        for(int i=1;i<n;i++){
            if(vp[i].first-vp[i-1].first<=k){
                c++;
            }
            else{
                sort(idx.begin()+i-c,idx.begin()+i);
                c=1;
            }
        }
        sort(idx.begin()+n-c,idx.begin()+n);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[idx[i]]=vp[i].first;
        }
        return ans;
    }
};