struct node {
    int x;
    int type;
    int height;
    node(int x, int type, int height) : x(x), type(type), height(height) {}
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<node> events;

        for (auto& b : buildings) {
            int l = b[0], r = b[1], h = b[2];
            events.emplace_back(l, 0, h); // Start of building
            events.emplace_back(r, 1, h); // End of building
        }

        sort(events.begin(), events.end(), [](const node& a, const node& b) {
            if (a.x != b.x) return a.x < b.x;
            if (a.type != b.type) return a.type < b.type;
            if (a.type == 0) return a.height > b.height; // Taller building starts first
            return a.height < b.height; // Shorter building ends first
        });

        multiset<int> heights = {0}; // To track active heights
        vector<vector<int>> ans;
        int prevHeight = 0;

        for (auto& e : events) {
            if (e.type == 0) {
                heights.insert(e.height); // Add building height
            } else {
                heights.erase(heights.find(e.height)); // Remove building height
            }

            int curHeight = *heights.rbegin(); // Current maximum height
            if (curHeight != prevHeight) {
                ans.push_back({e.x, curHeight}); // Add key point
                prevHeight = curHeight; // Update previous height
            }
        }

        return ans;
    }
};
