class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       map<long long,long long> mp;
       long long n1=nums1.size();
       long long n2=nums2.size();
       for(auto i:nums1){
        mp[i]+=n2;
       }
       for(auto i:nums2){
        mp[i]+=n1;
       }
       long long ans=0;
       for(auto i:mp){
        if(i.second&1){
            ans^=i.first;
        }
       }
       return ans;

        
    }
};