class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(i%3){
                sum+=cost[i-1];
            }
           
        }
        return sum;
        

    }
};