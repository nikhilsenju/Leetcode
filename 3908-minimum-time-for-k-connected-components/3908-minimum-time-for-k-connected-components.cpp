class DSU {
public:
    vector<int> parent, size;
    int components;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        components = n;
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return;
        if (size[xr] < size[yr]) swap(xr, yr);
        parent[yr] = xr;
        size[xr] += size[yr];
        components--;
    }

    int getComponents() {
        return components;
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low = 0, high = 1e9, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            DSU dsu(n);

            for (auto& e : edges) {
                int u = e[0], v = e[1], t = e[2];
                if (t > mid) {
                    dsu.unite(u, v);
                }
            }

            if (dsu.getComponents() >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
