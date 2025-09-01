class Solution {
    struct Node {
        int pass, tot;
        double gain;
        Node(int p, int t) {
            pass = p;
            tot = t;
            gain = (double)(p + 1) / (t + 1) - (double)p / t;
        }
    };

    struct cmp {
        bool operator()(const Node &a, const Node &b) {
            return a.gain < b.gain; // max-heap by gain
        }
    };

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Node, vector<Node>, cmp> pq;

        for (auto &c : classes) {
            pq.push(Node(c[0], c[1]));
        }

        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            top.pass++;
            top.tot++;
            top.gain = (double)(top.pass + 1) / (top.tot + 1) - (double)top.pass / top.tot;
            pq.push(top);
        }

        double sum = 0.0;
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            sum += (double)x.pass / x.tot;
        }

        return sum / classes.size();
    }
};
