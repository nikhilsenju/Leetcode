class dsu {
public:
    vector<long long> parent, size;
    long long Number_of_Nodes, Number_of_Groups, Max_Group;

    dsu(long long Number_of_Nodes) : Number_of_Nodes(Number_of_Nodes), Number_of_Groups(Number_of_Nodes), Max_Group(1) {
        parent.resize(Number_of_Nodes + 1);
        size.resize(Number_of_Nodes + 1, 1);
        for (long long i = 1; i <= Number_of_Nodes; ++i) {
            parent[i] = i;
        }
    }

    long long up(long long x) {
        if (parent[x] != x) {
            parent[x] = up(parent[x]);
        }
        return parent[x];
    }

    bool is_same_Group(long long x, long long y) {
        return up(x) == up(y);
    }

    void unionbysize(long long x, long long y) {
        long long leader1 = up(x);
        long long leader2 = up(y);
        if (leader1 != leader2) {
            Number_of_Groups--;
            if (size[leader1] < size[leader2]) {
                swap(leader1, leader2);
            }
            parent[leader2] = leader1;
            size[leader1] += size[leader2];
            Max_Group = max(Max_Group, size[leader1]);
        }
    }

    long long getsize(long long x) {
        return size[up(x)];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& v) {
        int n = v.size();
        dsu ds(n);
        map<string,int> mp;
        for(int i=0;i<v.size();i++){
            auto vec = v[i];
            for(int j=1;j<vec.size();j++){
                if(mp.find(vec[j])!=mp.end()){
                    ds.unionbysize(mp[vec[j]],i);
                }
                else{
                    mp[vec[j]]=i;
                }

            }
        }
        map<int,vector<int>> com;
        for(int i=0;i<n;i++){
            int u = ds.up(i);
            com[u].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto i:com){
            int u = i.first;
            vector<string> tmp;
            tmp.push_back(v[u][0]);
            set<string> st;
            for(auto j:i.second){
                int idx = j;
                for(int k=1;k<v[idx].size();k++){
                    st.insert(v[idx][k]);
                }
            }
            for(auto j:st){
                tmp.push_back(j);
            }
            ans.push_back(tmp);
        }
        return ans;

        
    }
};