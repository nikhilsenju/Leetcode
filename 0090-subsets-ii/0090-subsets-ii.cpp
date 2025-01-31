class Solution {
public: 
    void f(int ind ,vector<int>&tmp, vector<int>&nums,vector<vector<int>>&ans){
          ans.push_back(tmp);
        
        for(int i = ind ;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            tmp.push_back(nums[i]);
            f(i+1,tmp,nums,ans);
            tmp.pop_back();
          
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int> tmp;
        f(0,tmp,nums,ans);
        return ans;

        
    }
};