class Solution {
public:
    int maxFreeTime(int t, int k, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int> v;
        v.push_back(0);
        int prev = 0;
        for(int i=0;i<n;i++){
            int dis = st[i]-prev;
            v.push_back(dis);
            prev = et[i]; 
        }
        v.push_back(t-et.back());
        v.push_back(0);
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
        int sum = 0;
        int maxi = 0;
        for(int i=0;i<=k;i++){
            sum+=v[i];
        }
        maxi = max(maxi,sum);
        for(int i=k+1;i<v.size();i++){
            sum=sum+v[i]-v[i-k-1];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};