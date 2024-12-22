struct node {
    int mx;
    node() {
        mx = -1e9; // Initialize with a very small value
    }
};

node merge(node a, node b) {
    node ans;
    ans.mx = max(a.mx, b.mx);
    return ans;
}

node t[4 * 200020];

void build(int id, int l, int r, vector<int>& v) {
    if (l == r) {
        t[id].mx = v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid, v);
    build(2 * id + 1, mid + 1, r, v);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) {
        return;
    }
    if (l == r) {
        t[id].mx = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int id, int l, int r, int lq, int rq) {
    if (l > rq || lq > r) {
        return node();
    }
    if (lq <= l && r <= rq) {
        return t[id];
    }
    int mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, lq, rq),
                 query(2 * id + 1, mid + 1, r, lq, rq));
}

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& ht,
                                        vector<vector<int>>& q) {
        int n = ht.size();
        build(1, 0, n - 1, ht);
        vector<int> ans;

        for (auto i : q) {
            int x = i[0];
            int y = i[1];
            if(x>y){swap(x,y);}
            if (x == y || ht[x] < ht[y]) {
                ans.push_back(y);
                continue;
            }

            node maxi = query(1, 0, n - 1, y + 1, n - 1);
            if (maxi.mx <=ht[x]) {
                ans.push_back(-1);
                continue;
            }

            int hi = n - 1;
            int lo = y + 1;
            int ans1 = -1;
            while (hi >= lo) {
                int mid = (hi + lo) / 2;
                node maxi = query(1, 0, n - 1, y + 1, mid);
                if (maxi.mx > ht[x]) {
                    ans1 = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};
