class Solution {
public:
    void f(string&curr,vector<string>&v,string &s,int n){
        if(curr.size()>=n){
            v.push_back(curr);
            return;
        }
        for(int i=0;i<s.size();i++){
            curr.push_back(s[i]);
            f(curr,v,s,n);
            curr.pop_back();
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st(nums.begin(),nums.end());
        vector<string>v;
        string s = "01";
        int n = nums[0].size();
        string curr;
        f(curr,v,s,n);
        for(auto i:v){
            if(!st.count(i)){
                return i;
            }
        }
        return "";
    }
};