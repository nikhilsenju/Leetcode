class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        int n = nums.size();
        vector<long long> v;
        st.push(nums[0]);
        long long cur;
        for(int i=1;i<n;i++){
            cur = nums[i];
            while(!st.empty() && st.top()==cur){
                cur+=st.top();
                st.pop();
            }
            st.push(cur);
        }
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};