class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size()-k;
        int mini = INT_MAX;
        int tot =0;
        for(auto i:v){
            tot+=i;
        }
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        mini = min(mini,sum);
        for(int i=n;i<v.size();i++){
            sum+=v[i];
            sum-=v[i-n];
            mini = min(mini,sum);
        }
        return tot-mini;

        
    }
};