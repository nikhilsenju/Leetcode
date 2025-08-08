class Solution {
public:
    vector<long long> sub;
    vector<long long> res;
    vector<vector<long long>>adj;
    void calsub(long long node ,long long par){
        sub[node]=1;
        for(auto i:adj[node]){
            if(i!=par){
                calsub(i,node);
                sub[node]+=sub[i];
            }
        }
    }
    pair<multiset<long long>,multiset<long long>> solve(long long node, long long par,vector<int>&cost){
        multiset<long long>st;
        multiset<long long>mt;
        st.insert(cost[node]);
        mt.insert(cost[node]);
        for(auto i:adj[node]){
            if(i!=par){
                auto p = solve(i,node,cost);
                auto ch = p.first;
                auto ch1 = p.second;
                for(auto j:ch){
                    st.insert(j);
                    if(st.size()>3){
                        st.erase(st.begin());
                    }

                }
                 for(auto j:ch1){
                    mt.insert(j);
                    if(mt.size()>2){
                       mt.erase(--mt.end());
                    }
                }
            }
        }
        if(st.size()<3){
            res[node]=1;
            return {st,mt};
        }
        long long ans = 1;
        for(auto i:st){
            ans*=i;
        }
        long long ans1 = 1;
        for(auto i:mt){
            ans1*=i;
        }
        ans1*=*(--st.end());
        if(max(ans1,ans)<0){
            res[node]=0;
        }
        else{
            res[node]=max(ans,ans1);
        }
        return {st,mt};
    }
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        long long n = cost.size();
        sub.resize(n,0);
        res.resize(n,0);
        adj.resize(n,{});
        for(auto i:edges){
            long long u = i[0];
            long long v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        calsub(0,-1);
        solve(0,-1,cost);
        return res;

    }
};
