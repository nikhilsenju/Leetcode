class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int maxi = 0;
        for(auto i:mp){
            int ele = i.first;
            int freq1 = i.second;
            int nextele = ele+1;
            if(mp.find(nextele)!=mp.end()){
                maxi = max(maxi,freq1+mp[nextele]);
            }
        }
        return maxi;
    }
};