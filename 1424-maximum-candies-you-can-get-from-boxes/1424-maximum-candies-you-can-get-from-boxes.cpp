class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        vector<int> canopen(n),used(n),hasbox(n);
        for(int i=0;i<n;i++){
            canopen[i]=status[i];
        }
        int ans = 0;
        for(auto i:initialBoxes){
            hasbox[i]=1;
            if(canopen[i]){
                ans+=candies[i];
                q.push(i);
                used[i]=1;
            }
        }
        while(!q.empty()){
            auto bbox = q.front();
            q.pop();
            for(auto k:keys[bbox]){
                canopen[k]=1;
                if(!used[k] && hasbox[k]){
                    ans+=candies[k];
                    q.push(k);
                    used[k]=1;
                }
            }
            for(auto k:containedBoxes[bbox]){
                hasbox[k]=1;
                if(!used[k] && canopen[k]){
                    ans+=candies[k];
                    q.push(k);
                    used[k]=1;
                }
            }


        }
        return ans;
    }
};