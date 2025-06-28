class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        vector<pair<int,int>> vp;
      
        for(auto i:v){
            int u = i[0];
            int v = i[1];
            vp.push_back({u,v});
          
        }
        sort(vp.begin(),vp.end(),[&](pair<int,int>&a,pair<int,int>&b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second<b.second;

        });
        
        int n = vp.size();
        int ans = 0;
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(vp[i].second<maxi){ans++;}
            else{
                maxi = vp[i].second;
            }
        }
        return ans;
       
    }
};