class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> del;
        long long sum = 0;
        for(int i=0;i<n;i++){
            del.push_back((nums[i]^k)-nums[i]);
            sum+=nums[i];
        }
        sort(del.begin(),del.end());
        reverse(del.begin(),del.end());
        for(auto  i:del){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i=0;i<del.size()-1;i+=2){
            int cur = del[i]+del[i+1];
            if(cur<=0){
                break;
            }
            cout<<cur<<" ";
            sum+=cur;
        }
        cout<<endl;
        return sum;

    }
};