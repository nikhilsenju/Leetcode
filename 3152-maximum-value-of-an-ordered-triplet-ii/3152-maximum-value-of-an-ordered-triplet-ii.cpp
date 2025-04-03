class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> premax,suffmax;
        premax.push_back(nums[0]);
        suffmax.push_back(nums[n-1]);
        int maxi = nums[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi,nums[i]);
            premax.push_back(maxi);
        }
        int maxii=nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxii=max(maxii,nums[i]);
            suffmax.push_back(maxii);
        }
        reverse(suffmax.begin(),suffmax.end());
        for(auto i:premax){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:suffmax){
            cout<<i<<" ";

        }
        cout<<endl;
        long long val = 0;
        for(int i=1;i<n-1;i++){
            val = max(val,(long long)((premax[i-1]-nums[i])*suffmax[i+1]));
        }
        return val;
        
        
    }
};