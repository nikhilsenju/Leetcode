class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,queue<int>> mp;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int val = nums[i];
            auto &q = mp[val];
            if(q.size()>=2){
                int a = q.front();q.pop();
                int b = q.front();q.pop();
                int c = i;
                int dis = abs(a-b)+abs(b-c)+abs(a-c);
                mini = min(mini,dis);
                q.push(b);
                q.push(c);
            }
            else{
                q.push(i);
            }
        }
        return mini == INT_MAX?-1:mini;
    }
};