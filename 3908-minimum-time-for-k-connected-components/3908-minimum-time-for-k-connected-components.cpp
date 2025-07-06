class dsu {
public:
    vector<int> parent, size;
    int Number_of_Groups;

    dsu(int n) : parent(n), size(n, 1), Number_of_Groups(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unionbysize(int x, int y) {
        int lx = find(x);
        int ly = find(y);
        if (lx == ly) return;
        if (size[lx] < size[ly]) swap(lx, ly);
        parent[ly] = lx;
        size[lx] += size[ly];
        Number_of_Groups--;
    }
};

class Solution {
public:
    bool atleastkwithintime(int mid, int k, vector<vector<int>>& edges, int n) {
        dsu ds(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            if (t > mid) {
                ds.unionbysize(u, v);
            }
        }
        return ds.Number_of_Groups >= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        int lo = 0, hi = 1e9, ans = -1;
        while (lo <= hi) {
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
