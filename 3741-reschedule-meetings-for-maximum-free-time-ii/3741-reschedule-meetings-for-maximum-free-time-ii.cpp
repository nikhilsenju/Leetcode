class Solution {
public:
    int maxFreeTime(int et, vector<int>& st, vector<int>& end) {
        int n = st.size();
        int prev = 0;
        multiset<int> mt;
        vector<int> v;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int curst = st[i];
            int curend = end[i];
            int dis = curst - prev;
            maxi = max(maxi, dis);
            mt.insert(dis);
            v.push_back(dis);
            prev = curend;
        }
        v.push_back(et - prev);
        mt.insert(et - prev);
        maxi = max(maxi, et - prev);
        for (int i = 0; i < v.size() - 1; i++) {
            int d1 = v[i];
            int d2 = v[i + 1];
            maxi = max(maxi,d1+d2);
            int d = end[i] - st[i];
            mt.erase(mt.find(d1));
            mt.erase(mt.find(d2));
            if (!mt.empty()) {
                auto it = *(--mt.end());
                if(it>=d){
                    maxi = max(maxi,d1+d2+d);
                }
            }
            mt.insert(d1);
            mt.insert(d2);
        }
        return maxi;
    }
};