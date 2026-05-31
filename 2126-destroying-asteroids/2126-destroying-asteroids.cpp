class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        long long sum = mass;
        for(auto i:v){
            if(i<=sum){
                sum+=i;
            }
            else{
                return false;
            }
        } 
        return true;
    }
};