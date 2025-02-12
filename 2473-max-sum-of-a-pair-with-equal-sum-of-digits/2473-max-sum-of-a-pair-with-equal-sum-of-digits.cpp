class Solution {
public:
    int sumof(int num){
        string s = to_string(num);
        int sum = 0;
        for(auto i:s){
            sum+=i-'0';

        }
        return sum;

    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        map<int,int> mp;
        for(auto i:nums){
            int cur = sumof(i);
            if(mp.find(cur)!=mp.end()){
                maxi = max (maxi,i+mp[cur]);
            }
            mp[cur]=max(mp[cur],i);
        }
        return maxi;

        
    }
};