class Solution {
public:
    struct Node {
        string s;
        int steps;
        Node(string s, int steps) : s(s), steps(steps) {};
    };
    int ladderLength(string st, string end ,vector<string>& v) {
        unordered_set<string> used(v.begin(), v.end());
        queue<Node> q;
        q.push(Node(st, 1));
        if (used.count(st)) {
            used.erase(st);
        }
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            string curr = it.s;
            int steps = it.steps;
            if (curr == end) {
                return steps;
            }
            for (int i = 0; i < curr.size(); i++) {
                string tmp = curr;
                for (char c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if (used.find(tmp)!=used.end()){
                            used.erase(tmp);
                            q.push(Node(tmp, steps + 1));
                        }
                }
            }
        }
        return 0;
    }
};