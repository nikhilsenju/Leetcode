class Solution {
    const int mod=1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        map<int,int> mp;
        mp[0]=1;
        int ans = 0;

        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum&1){
                ans=(ans+mp[0])%mod;

            }
            else{
                ans=(ans+mp[1])%mod;

            }
            mp[sum&1]++;
        }
        return ans;
    }
};