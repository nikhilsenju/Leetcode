class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int sum = 0;
        int maxi = INT_MIN;
        for(auto i:nums){
            if(i>0){
                st.insert(i);
            }  
            else{
                maxi = max(maxi,i);
            }
        }
        if(!st.size()){
            return maxi;
        }
        for(auto i:st){
            sum+=i;
        }
        return sum;
    }

};