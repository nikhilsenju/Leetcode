class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-n+1;i++){
            vector<int> v;
            for(int j=i;j<i+n;j++){
                v.push_back(nums[j]);
            }
            if(tmp==v){return true;}
        }
        
        return false;
    }
};