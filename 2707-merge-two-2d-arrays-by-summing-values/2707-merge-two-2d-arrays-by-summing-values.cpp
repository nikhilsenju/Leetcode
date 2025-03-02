class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int maxi = 0;
        for(auto i:nums1){
            maxi = max(maxi,i[0]);
        }
        for(auto i:nums2){
            maxi =max(maxi,i[0]);
        }
        vector<int> v(maxi+1,0);
        for(auto i:nums1){
            v[i[0]]+=i[1];
        }
        for(auto i:nums2){
            v[i[0]]+=i[1];
        }
        vector<vector<int>> vp;
        for(int i=0;i<maxi;i++){
            if(v[i+1]!=0){

            
            vp.push_back({i+1,v[i+1]});
            }
        }
        return vp;
        
    }
};