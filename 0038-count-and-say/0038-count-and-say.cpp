class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        n--;
        while (n--) {
            string tmp;
            char ch = s[0];
            int c = 0;
            for (int i = 0; i < s.size(); i++) {
                if (ch == s[i]) {
                    c++;
                } else {
                    string cnt = to_string(c);
                    tmp += cnt;
                    tmp.push_back(ch);
                    ch = s[i];
                    c = 1;
                }
            }
            string cnt = to_string(c);
            tmp += cnt;
            tmp.push_back(ch);
            s=tmp;
        }
        return s;
    }
};