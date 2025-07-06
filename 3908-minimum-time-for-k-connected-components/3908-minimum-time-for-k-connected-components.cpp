class dsu {
public:
    vector<long long> parent, size;
    long long Number_of_Groups;

    dsu(long long n) : Number_of_Groups(n) {
        parent.resize(n);
        size.resize(n, 1);
        for (long long i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    long long up(long long x) {
        if (parent[x] != x) {
            parent[x] = up(parent[x]);
        }
        return parent[x];
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
        }
    }
};

class Solution {
public:
    bool atleastkwithintime(int mid, int k, vector<vector<int>>& adj, int n) {
        dsu ds(n);
        for (auto& i : adj) {
            int u = i[0], v = i[1], t = i[2];
            if (mid < t) {
                ds.unionbysize(u, v);
            }
        }
        return ds.Number_of_Groups >= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        int lo = 0, hi = 1e9, ans = -1;
        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (atleastkwithintime(mid, k, edges, n)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
