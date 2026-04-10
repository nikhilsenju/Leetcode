class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int mini = INT_MAX;
        for(auto i:mp){
            auto v = i.second;
            if(v.size()>=3){
                for(int j=2;j<v.size();j++){
                    mini = min(mini,abs(v[j]-v[j-1])+abs(v[j-1]-v[j-2])+abs(v[j]-v[j-2]));
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};