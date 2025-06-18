class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int fl = 0;
        for(int i=0;i<n/3;i++){
            vector<int> tmp;
            for(int j=3*i;j<3*i+3;j++){
                tmp.push_back(nums[j]);
            }
            if(tmp[2]-tmp[0]>k){
                fl=1;
                break; 
            }
            ans.push_back(tmp);
        }
        if(fl){
            vector<vector<int>> v;
            return v;
        }
        return ans;

        
    }
};