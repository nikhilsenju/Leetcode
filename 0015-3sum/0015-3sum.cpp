class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=2;i<n;i++){
            int tar = -nums[i];
            int left = 0;
            int right = i-1;
            vector<int> tmp;
            while(right>left){
                if(nums[left]+nums[right]>=tar){
                    if(nums[left]+nums[right]==tar){
                        ans.insert({nums[left],nums[right],nums[i]});

                    }
                    right--;
                }
                else{
                    left++;
                }
            }
            

        }
        vector<vector<int>> res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};