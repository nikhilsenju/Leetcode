class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(auto i:nums){
            v.push_back(i);
        }
        sort(v.begin(),v.end());
        int ele = v[n/2];
        int count=0;
        for(auto i:nums){
            if(i==ele){count++;}
        }
        int idx = -1;
        int pre = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==ele){
                pre++;
                count--;
            }
            int pref = (i+1)/2;
            int suff = (n-i-1)/2;
            if(pre>pref && count>suff){
                return i;
            }
        }
        return -1;

        
    }
};